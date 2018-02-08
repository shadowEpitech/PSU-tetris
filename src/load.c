/*
** load.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:14:13 2017 nicolas djurovic
** Last update Sun Mar 19 17:51:29 2017 Nelson ANGELIQUE
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"
#include "tools.h"

int		get_shape(int fd, t_tetri *tetris)
{
  int		i;
  char		*str;

  if (!(tetris->arr = malloc(sizeof(char *) * (tetris->height + 1))))
    return (tetris->arr = NULL, 1);
  tetris->arr[tetris->height] = NULL;
  i = -1;
  while ((str = get_next_line(fd)))
    {
      if (++i < tetris->height && !(tetris->arr[i] = my_strdup(str)))
	return (free(str), 1);
      free(str);
    }
  if (i != tetris->height - 1)
    return (error("Error while parsing tetrimino\n"));
  return (set_color(tetris), 0);
}

int		get_infos(int fd, t_tetri *tetris, int width, int height)
{
  char		*str;
  char		**infos;

  if (!(str = get_next_line(fd)) ||
      !(infos = my_str_to_wordtab(str, 3)))
    return (error("Cannot malloc\n"));
  free(str);
  if ((tetris->width = my_getnbr(infos[0])) < 1 || tetris->width > width ||
      (tetris->height = my_getnbr(infos[1])) < 1 || tetris->height > height ||
      (tetris->color = my_getnbr(infos[2])) < 1 || tetris->color > 7)
    tetris->error = true;
  free2DArray(infos);
  return (get_shape(fd, tetris));
}

int		getTetrimino(char *name, t_tetri *tetris, t_game *game)
{
  int		fd;

  if (!(tetris->name = cle_name(my_strdup(name))))
    return (1);
  if (!(name = add_dir_name(name)))
    return (error("Cannot malloc\n"));
  if ((fd = open(name, O_RDONLY)) < 0)
    return (free(name), error("Cannot open file\n"));
  free(name);
  if (get_infos(fd, tetris, game->width, game->height))
    return (close(fd), 1);
  if (close(fd) < 0)
    return (error("Cannot close file\n"));
  return (0);
}

t_tetri		*malloc_tetri_arr(t_tetri *tetris)
{
  DIR		*dir;
  int		i;
  struct dirent	*dent;

  i = 0;
  dir = NULL;
  if (!(dir = opendir("tetriminos")))
    return (NULL);
  while ((dent = readdir(dir)))
    if (my_strcmp(dent->d_name, ".\0") &&
	my_strcmp(dent->d_name, "..\0") && check_file(dent->d_name))
      i++;
  if (!(tetris = malloc(sizeof(t_tetri) * (i + 1))))
    return (closedir(dir), NULL);
  my_memset(tetris, 0, sizeof(t_tetri) * (i + 1));
  tetris[i].color = -1;
  return ((closedir(dir) == -1) ? NULL : tetris);
}

t_tetri		*load_tetri(t_tetri *tetris, t_game *game)
{
  DIR		*dir;
  int		j;
  char		**names;

  if (!(tetris = malloc_tetri_arr(tetris)) ||
      !(dir = opendir("tetriminos")))
    return (free(tetris), NULL);
  if (!(names = getNames(dir)))
    return (closedir(dir), free(tetris), NULL);
  j = -1;
  while (names[++j])
    if (getTetrimino(names[j], &tetris[j], game))
      return (closedir(dir), free(tetris), free2DArray(names), NULL);
  if (closedir(dir) == -1)
    return (free(tetris), free2DArray(names), NULL);
  return (free2DArray(names), tetris);
}
