/*
** init_game.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:57 2017 nicolas djurovic
** Last update Sun Mar 19 17:51:17 2017 Nelson ANGELIQUE
*/

#include <signal.h>
#include "tetris.h"

void	size(int signal)
{
  (void)signal;
  return ;
}

int	init_game(t_game *game)
{
  if (signal(SIGWINCH, size) == SIG_ERR)
    return (1);
  if (!(game->arr = malloc_tab(game->arr, game->height, game->width)) ||
      !(game->tetris = malloc(sizeof(t_tetri))))
    return (1);
  return (0);
}

char	**malloc_tab(char **array, int height, int width)
{
  int	j;

  if (!(array = malloc(sizeof(char *) * (height + 1))))
    return (NULL);
  j = -1;
  while (++j < height)
    {
      if (!(array[j] = malloc(sizeof(char) * width + 1)))
	return (NULL);
      my_memset(array[j], -1, width + 1);
    }
  array[height] = NULL;
  return (array);
}

int            create_win(t_window *win, t_game *game)
{
  win->next = NULL;
  if (!(win->title = newwin(6, 30, 0, 0)) ||
      !(win->score = create_win2(10, 25, 8, 4)) ||
      !(win->board =
	create_board(game->height + 2, game->width + 2, 1, 32)))
    return (1);
  return (0);
}
