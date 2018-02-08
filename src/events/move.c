/*
** move.c for  in /home/shadow/tetris/src/events
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:09 2017 nicolas djurovic
** Last update Sun Mar 19 17:50:50 2017 Nelson ANGELIQUE
*/

#include "tetris.h"

int	key_left_event(t_game *game)
{
  if (game->tetris->x == 0)
    return (0);
  clean_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  if (check_print_tetri(game->tetris, game,
			game->tetris->x - 1, game->tetris->y))
    {
      print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
      return (0);
    }
  game->tetris->x -= 1;
  print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  return (0);
}

int	key_right_event(t_game *game)
{
  clean_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  if (check_print_tetri(game->tetris, game,
			game->tetris->x + 1, game->tetris->y))
    {
      print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
      return (0);
    }
  game->tetris->x += 1;
  print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  return (0);
}

int	key_turn_event(t_game *game)
{
  (void) game;
  return (0);
}

int	key_drop_event(t_game *game)
{
  int	i;

  i = 0;
  clean_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  while (!check_print_tetri(game->tetris, game,
			   game->tetris->x, game->tetris->y + i))
    i++;
  game->tetris->y += (i - 1);
  print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  return (0);
}
