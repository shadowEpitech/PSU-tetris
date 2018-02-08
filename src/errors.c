/*
** errors.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:01 2017 nicolas djurovic
** Last update Sun Mar 19 14:13:02 2017 nicolas djurovic
*/

#include "tools.h"

int	error(const char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
