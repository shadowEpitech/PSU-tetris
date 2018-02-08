/*
** check_file.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:11:58 2017 nicolas djurovic
** Last update Sun Mar 19 14:11:59 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

int	check_file(char *name)
{
  int	j;

  j = -1;
  if (name[0] == '.')
    ++j;
  while (name[++j] != 0 && name[j] != '.');
  if (my_strncmp(name + j, ".tetrimino", 10))
    return (0);
  return (1);
}
