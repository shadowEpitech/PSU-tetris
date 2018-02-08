/*
** my_memset.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:14:44 2017 nicolas djurovic
** Last update Sun Mar 19 14:14:45 2017 nicolas djurovic
*/

#include "tetris.h"

void	my_memset(void *m, char c, int size)
{
  unsigned char	*str;

  str = m;
  while (size--)
    str[size] = c;
}
