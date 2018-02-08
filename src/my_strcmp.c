/*
** my_strcmp.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:15:06 2017 nicolas djurovic
** Last update Sun Mar 19 14:15:10 2017 nicolas djurovic
*/

#include "tools.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;
  int	j;
  int	t;

  i = 0;
  j = 0;
  t = my_strlen(s1);
  if (t < my_strlen(s2))
    t = my_strlen(s2);
  while (i < t + 1 && !j)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return (j);
}
