/*
** copy_tetri.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:12:35 2017 nicolas djurovic
** Last update Sun Mar 19 17:47:28 2017 Nelson ANGELIQUE
*/

#include "tetris.h"

int	copy_tetris(t_tetri *tetri, t_game *game)
{
  int	i;
  int	j;

  i = -1;
  game->tetris->width = tetri->width;
  game->tetris->height = tetri->height;
  game->tetris->x = tetri->x;
  game->tetris->y = tetri->y;
  game->tetris->color = tetri->color;
  game->tetris->name = NULL;
  game->tetris->error = false;
  if (!(game->tetris->arr = malloc(sizeof(char *)
				   * (game->tetris->height + 1))))
    return (1);
  game->tetris->arr[game->tetris->height] = NULL;
  while (++i < game->tetris->height)
    {
      if (!(game->tetris->arr[i] = malloc(sizeof(char) * game->tetris->width)))
	return (1);
      j = -1;
      while (++j < game->tetris->width)
	game->tetris->arr[i][j] = tetri->arr[i][j];
    }
  return (0);
}
