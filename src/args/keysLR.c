/*
** keysLR.c for  in /home/shadow/tetris/src/args
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:10:21 2017 nicolas djurovic
** Last update Sun Mar 19 14:10:22 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

int	key_left_arg(t_game *game, char **argv, bool mode)
{
  if (mode == SHORT)
    {
      if (!argv[1] || !(game->keys[LEFT] = my_strdup(argv[1])))
	return (1);
    }
  else if (mode == LONG)
    {
      if (my_strlen(argv[0]) <= 11 ||
	  !(game->keys[LEFT] = my_strdup(argv[0] + 11)))
	return (1);
    }
  return (0);
}

int	key_right_arg(t_game *game, char **argv, bool mode)
{
  if (mode == SHORT)
    {
      if (!argv[1] || !(game->keys[RIGHT] = my_strdup(argv[1])))
	return (1);
    }
  else if (mode == LONG)
    {
      if (my_strlen(argv[0]) <= 12 ||
	  !(game->keys[RIGHT] = my_strdup(argv[0] + 12)))
	return (1);
    }
  return (0);
}
