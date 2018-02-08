/*
** add_dir_name.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:09:29 2017 nicolas djurovic
** Last update Sun Mar 19 17:46:20 2017 Nelson ANGELIQUE
*/

#include "tetris.h"
#include "tools.h"

char	*add_dir_name(char *name)
{
  int	i;
  int	j;
  char	*result;
  char	*dir;

  i = -1;
  j = -1;
  if (!(dir = my_strdup("tetriminos/")) ||
      !(result = malloc(sizeof(char)
			* (my_strlen(name)
			   + my_strlen(dir) + 1))))
    return (NULL);
  while (dir[++i] != 0)
    result[i] = dir[i];
  while (name[++j] != 0)
    result[i++] = name[j];
  result[i] = 0;
  free(dir);
  return (result);
}
