/*
** order.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:16:00 2017 nicolas djurovic
** Last update Sun Mar 19 14:16:01 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

void		set_color(t_tetri *tetris)
{
  int		i;
  int		j;

  i = -1;
  while (tetris->arr[++i] && (j = -1))
    while (tetris->arr[i][++j])
      if (tetris->arr[i][j] == '*')
	tetris->arr[i][j] = (char)tetris->color;
      else
	tetris->arr[i][j] = -1;
}

int		count_files(void)
{
  DIR		*count;
  struct dirent	*file;
  int		i;

  i = 0;
  if (!(count = opendir("tetriminos")))
    return (0);
  while ((file = readdir(count)))
    if (my_strcmp(file->d_name, ".\0") &&
	my_strcmp(file->d_name, "..\0") && check_file(file->d_name))
      ++i;
  if (closedir(count) < 0)
    return (0);
  return (i);
}

int		isOrdered(const char **name)
{
  int		i;
  int		j;

  i = -1;
  while (name[++i] && (j = i) > -1)
    {
      while (name[++j])
	{
	  if (my_strcmp(name[i], name[j]) > 0)
	    return (1);
	}
    }
  return (0);
}

char		**orderNames(char **name)
{
  char		*tmp;
  int		i;
  int		j;

  i = -1;
  while (isOrdered((const char **)name) && name[++i] && (j = i) > -1)
    {
      while (name[++j])
	{
	  if (my_strcmp(name[i], name[j]) > 0)
	    {
	      if (!(tmp = my_strdup(name[i])))
		return (error("Cannot malloc\n"), NULL);
	      if (free(name[i]), !(name[i] = my_strdup(name[j])))
		return (error("Cannot malloc\n"), NULL);
	      if (free(name[j]), !(name[j] = my_strdup(tmp)))
		return (error("Cannot malloc\n"), NULL);
	      free(tmp);
	    }
	}
    }
  return (name);
}

char		**getNames(DIR *dir)
{
  int		i;
  struct dirent	*file;
  char		**names;
  int		nb;

  if (!(nb = count_files()))
    return (error("Not enough tetrimino\n"), NULL);
  if (!(names = malloc(sizeof(char *) * (nb + 1))))
    return (error("Cannot malloc\n"), NULL);
  i = 0;
  while ((file = readdir(dir)))
    if (my_strcmp(file->d_name, ".\0") &&
	my_strcmp(file->d_name, "..\0") && check_file(file->d_name) &&
	!(names[i++] = my_strdup(file->d_name)))
      return (error("Cannot malloc\n"), NULL);
  names[nb] = NULL;
  return ((names = orderNames(names)));
}
