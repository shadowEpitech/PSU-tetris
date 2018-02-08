/*
** board.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:11:29 2017 nicolas djurovic
** Last update Sun Mar 19 14:11:30 2017 nicolas djurovic
*/

#include "tetris.h"

WINDOW		*create_board(int height, int width, int y,
				  int x)
{
  WINDOW	*win;

  if (!(win = newwin(height, width, y, x)))
    return (NULL);
  wborder(win, '|', '|', '-', '-', '-', '-', '-', '-');
  return (win);
}

void		display_tetris(WINDOW *win, char **arr, int width)
{
  int		i;
  int		j;

  i = -1;
  while (arr[++i])
    {
      j = -1;
      while (++j < width)
	if (arr[i][j] > -1)
	  {
	    wattrset(win, COLOR_PAIR(arr[i][j]));
	    mvwprintw(win, i + 1, j + 1, "*");
	  }
    }
}

void		display_next(WINDOW *win, t_tetri *tetris)
{
  int		i;
  int		j;

  i = -1;
  while (++i < tetris->height)
    {
      j = -1;
      while (++j < tetris->width)
	if (tetris->arr[i][j] == tetris->color)
	  {
	    wattrset(win, COLOR_PAIR(tetris->color));
	    mvwprintw(win, i + 1, j + 1, "*");
	  }
    }
}

void		display_board(t_window *win, t_tetri *tetris, t_game *game)
{
  display_tetris(win->board, game->arr, game->width);
  mvwprintw(win->next, 0, 1, "Next");
  if (game->showNext)
    display_next(win->next, tetris);
  wrefresh(win->board);
  wrefresh(win->next);
}
