/*
** check_line.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:12:06 2017 nicolas djurovic
** Last update Sun Mar 19 14:12:08 2017 nicolas djurovic
*/

#include "tetris.h"

void	all_tetri(t_game *game, int index)
{
  int	i;

  while ((i = -1) && index > 1)
    {
      while (++i < game->width)
	game->arr[index][i] = game->arr[index - 1][i];
      --index;
    }
  while (++i < game->width)
    game->arr[0][i] = -1;
}

int	line_full(t_game *game, int index)
{
  int	i;

  i = -1;
  while (++i < game->width)
    if (game->arr[index][i] < 0)
      return (0);
  i = -1;
  while (++i < game->width)
    game->arr[index][i] = -1;
  return (1);
}

int	check_line(t_game *game)
{
  int	j;

  if (game->tetris->y == 0)
    game->end = true;
  j = game->tetris->y - 1;
  while (++j < game->tetris->y + game->tetris->height)
    if (line_full(game, j))
      {
	game->score += 100;
	game->line += 1;
	game->level = (game->line / 10) + 1;
	all_tetri(game, j);
      }
  return (1);
}
