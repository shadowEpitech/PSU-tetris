/*
** random_tetri.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:16:28 2017 nicolas djurovic
** Last update Sun Mar 19 14:16:30 2017 nicolas djurovic
*/

#include "tetris.h"

int		random_tetri(t_tetri *tetris)
{
  int		i;
  time_t	t;

  i = -1;
  while (tetris[++i].color != -1);
  srand((unsigned) time(&t));
  i = rand() % (i -1);
  return (i);
}
