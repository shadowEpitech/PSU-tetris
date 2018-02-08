/*
** free.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:26 2017 nicolas djurovic
** Last update Sun Mar 19 14:13:27 2017 nicolas djurovic
*/

#include "tetris.h"

void	free_tetris(t_tetri *tetris)
{
  int	j;

  j = 0;
  while (tetris[j].color != -1)
    {
      free(tetris[j].name);
      free2DArray(tetris[j].arr);
      ++j;
    }
  free2DArray(tetris[j].arr);
  free(tetris);
}

void	freeWin(t_window *win)
{
  delwin(win->title);
  delwin(win->score);
  delwin(win->board);
  delwin(win->next);
}

void	freeKeys(char **keys)
{
  free(keys[QUIT]);
  free(keys[PAUSE]);
}

void	free2DArray(char **str)
{
  int	i;

  i = 0;
  while (str && str[i])
    free(str[i++]);
  free(str);
}
