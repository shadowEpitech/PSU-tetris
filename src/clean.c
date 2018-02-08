/*
** clean_name.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:12:27 2017 nicolas djurovic
** Last update Sun Mar 19 14:12:27 2017 nicolas djurovic
*/

#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

char	*cle_name(char *str)
{
  int	j;
  char	*result;

  j = -1;
  if (!(result = malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (write(2, "Malloc failed\n", 14), NULL);
  if (str[0] == '.' && ++j > -1)
    result[0] = '.';
  while (str && str[++j] && str[j] != '.' && (result[j] = str[j]));
  result[j] = '\0';
  return (free(str), result);
}
