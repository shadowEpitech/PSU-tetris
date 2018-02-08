/*
** my_strncmp.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:15:32 2017 nicolas djurovic
** Last update Sun Mar 19 14:15:33 2017 nicolas djurovic
*/

#include "tools.h"

int	my_strncmp(const char *s1, const char *s2, int n)
{
  while (n > 0)
    {
      if (*s1 == '\0' || *s1 != *s2)
	return (*s1 - *s2);
      ++s1;
      ++s2;
      --n;
    }
  return (*s1 - *s2);
}
