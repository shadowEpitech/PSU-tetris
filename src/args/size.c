/*
** size.c for  in /home/shadow/tetris/src/args
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:11:04 2017 nicolas djurovic
** Last update Sun Mar 19 14:11:05 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

int	parse_size(const char *str, t_game *game)
{
  int	i;
  int	j;
  int	r;
  int	c;
  char	*tmp;

  str += 11;
  i = 0;
  j = 0;
  while (str[i] && str[i] != ',' && ++i);
  if (!(tmp = malloc(sizeof(char) * (i + 1))))
    return (1);
  while (j < i && (tmp[j] = str[j]) && ++j);
  tmp[i] = '\0';
  str += ++i;
  if (!BETWEEN((r = my_getnbr(tmp)), MIN_ROW, MAX_ROW) ||
      !BETWEEN((c = my_getnbr(str)), MIN_COL, MAX_COL))
    return (free(tmp), write(2, "Incorrect size\n", 15), 1);
  game->height = r;
  game->width = c;
  return (free(tmp), 0);
}

int	size_arg(t_game *game, char **argv, bool mode)
{
  (void)mode;
  if (my_strlen(argv[0]) <= 11 || parse_size(argv[0], game))
    return (1);
  return (0);
}
