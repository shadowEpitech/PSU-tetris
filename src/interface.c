/*
** interface.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:14:05 2017 nicolas djurovic
** Last update Sun Mar 19 14:14:06 2017 nicolas djurovic
*/

#include "tetris.h"

WINDOW		*create_win2(int height, int width, int y, int x)
{
  WINDOW	*win;

  if (!(win = newwin(height, width, y, x)))
    return (NULL);
  wborder(win, '|', '|', '-', '-', '/', '\\', '\\', '/');
  return (win);
}

void		pair_color(void)
{
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void		display_title(WINDOW *win)
{
  wattrset(win, COLOR_PAIR(2));
  mvwprintw(win, 1, 16, "***");
  mvwprintw(win, 2, 16, "* *");
  mvwprintw(win, 3, 16, "** ");
  mvwprintw(win, 4, 16, "* *");
  mvwprintw(win, 5, 16, "* *");
  wattrset(win, COLOR_PAIR(6));
  mvwprintw(win, 1, 20, " * ");
  mvwprintw(win, 2, 20, "   ");
  mvwprintw(win, 3, 20, " * ");
  mvwprintw(win, 4, 20, " * ");
  mvwprintw(win, 5, 20, " * ");
  wattrset(win, COLOR_PAIR(5));
  mvwprintw(win, 1, 24, "***");
  mvwprintw(win, 2, 24, "*  ");
  mvwprintw(win, 3, 24, "***");
  mvwprintw(win, 4, 24, "  *");
  mvwprintw(win, 5, 24, "***");
}

void		display_title2(WINDOW *win)
{
  wattrset(win, COLOR_PAIR(1));
  mvwprintw(win, 1, 4, "***");
  mvwprintw(win, 2, 4, " * ");
  mvwprintw(win, 3, 4, " * ");
  mvwprintw(win, 4, 4, " * ");
  mvwprintw(win, 5, 4, " * ");
  wattrset(win, COLOR_PAIR(4));
  mvwprintw(win, 1, 8, "***");
  mvwprintw(win, 2, 8, "*  ");
  mvwprintw(win, 3, 8, "***");
  mvwprintw(win, 4, 8, "*  ");
  mvwprintw(win, 5, 8, "***");
  wattrset(win, COLOR_PAIR(3));
  mvwprintw(win, 1, 12, "***");
  mvwprintw(win, 2, 12, " * ");
  mvwprintw(win, 3, 12, " * ");
  mvwprintw(win, 4, 12, " * ");
  mvwprintw(win, 5, 12, " * ");
  display_title2(win);
}

void		display_interface(t_window *win, t_game *game)
{
  display_score(win->score, game);
  wborder(win->score, '|', '|', '-', '-', '/', '\\', '\\', '/');
  display_title(win->title);
  wrefresh(win->title);
  wrefresh(win->score);
}
