/*
** add_tetri.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:09:54 2017 nicolas djurovic
** Last update Sun Mar 19 14:09:55 2017 nicolas djurovic
*/

#include "tetris.h"

int	check_print_tetri(t_tetri *tetris, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = -1;
  tmp = x;
  if ((y + tetris->height - 1) > game->height)
    return (1);
  while (++i < tetris->height && y < game->height)
    {
      x = tmp;
      j = -1;
      while (++j < tetris->width && x < game->width)
	{
	  if (tetris->arr[i][j] == tetris->color && game->arr[y][x] > -1)
	    return (1);
	  x++;
	}
      y++;
    }
  if (i < tetris->height || j < tetris->width)
    return (1);
  return (0);
}

void	print_tetri(t_tetri *tetris, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  tmp = x;
  while (i < tetris->height)
    {
      x = tmp;
      j = 0;
      while (j < tetris->width)
	{
	  if (tetris->arr[i][j] == tetris->color)
	    game->arr[y][x] = tetris->color;
	  ++x;
	  ++j;
	}
      ++i;
      ++y;
    }
}

void	clean_tetri(t_tetri *tetris, t_game *game, int x, int y)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  tmp = x;
  while (i < tetris->height)
    {
      x = tmp;
      j = 0;
      while (j < tetris->width)
	{
	  if (tetris->arr[i][j] == tetris->color)
	    game->arr[y][x] = -1;
	  ++x;
	  ++j;
	}
      ++i;
      ++y;
    }
}

int	add_tetri(t_tetri *tetri, t_game *game)
{
  game->cur = game->next;
  game->next = random_tetri(tetri);
  copy_tetris(&tetri[game->cur], game);
  game->tetris->x = (game->width / 2) - (game->tetris->width / 2) - 1;
  game->tetris->y = 0;
  if (check_print_tetri(game->tetris, game,
			game->tetris->x, game->tetris->y))
    return (check_line(game));
  print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  return (0);
}

int     tetri(t_game *game)
{
  clean_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  if (check_print_tetri(game->tetris, game,
			game->tetris->x, game->tetris->y + 1))
    return (print_tetri(game->tetris, game, game->tetris->x, game->tetris->y),
	    check_line(game));
  game->tetris->y += 1;
  print_tetri(game->tetris, game, game->tetris->x, game->tetris->y);
  return (0);
}
