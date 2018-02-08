/*
** level.c for tetris in /home/Nelson.ANGELIQUE/Prog/Rendus/PSU_2016_tetris
** 
** Made by Nelson ANGELIQUE
** Login   <Nelson.ANGELIQUE@epitech.net>
** 
** Started on  Sun Mar 19 17:48:47 2017 Nelson ANGELIQUE
** Last update Sun Mar 19 17:48:49 2017 Nelson ANGELIQUE
*/

#include "tetris.h"
#include "tools.h"

int	level(const char *str)
{
  str += 8;
  return (my_getnbr(str));
}

int	level_arg(t_game *game, char **argv, bool mode)
{
  int	i;

  if (mode == SHORT && argv[1])
    i = ((argv[1]) ? my_getnbr(argv[1]) : 0);
  else if (mode == LONG && my_strlen(argv[0]) > 8)
    i = level(argv[0]);
  else
    return (1);
  if (i)
    game->level = i;
  else
    {
      write(2, "Incorrect level\n", 16);
      return (1);
    }
  return (0);
}
