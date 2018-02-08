/*
** display.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:12:54 2017 nicolas djurovic
** Last update Sun Mar 19 14:12:55 2017 nicolas djurovic
*/

#include "tetris.h"

int		display1(t_window *win, t_game *game, char *term)
{
  if (!(initscr()))
    return (error("Cannot start new term\n"));
  if (init_term(term, false))
    return (error("Cannot init term\n"));
  curs_set(0);
  start_color();
  pair_color();
  if (create_win(win, game))
    return (error("Cannot create windows\n"));
  return (0);
}

int		display2(t_window *win, t_tetri *next, t_game *game)
{
  int		c;
  int		line;

  c = 0;
  line = 0;
  if (win->next)
    {
      wclear(win->next);
      werase(win->next);
      wrefresh(win->next);
      delwin(win->next);
    }
  getmaxyx(stdscr, line, c);
  if ((game->width + next->width + 40) > c || game->height > line)
    return (error("Window too small"));
  if (!(win->next =
	create_win2(next->height + 2, next->width + 4, 1, game->width + 36)))
    return (error("Cannot create window\n"));
  display_interface(win, game);
  werase(win->board);
  wattrset(win->board, COLOR_PAIR(7));
  wborder(win->board, '|', '|', '-', '-', '-', '-', '-', '-');
  display_board(win, next, game);
  return (0);
}
