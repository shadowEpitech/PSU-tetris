/*
** my_str_to_wordtab.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:15:53 2017 nicolas djurovic
** Last update Sun Mar 19 14:15:53 2017 nicolas djurovic
*/

#include "tools.h"

char	**my_str_to_wordtab(const char *str, const int line)
{
  char	**tab;
  int	count;
  int	i;
  int	j;

  if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  count = -1;
  while (++count < line)
    {
      i = -1;
      j = -1;
      while (str[++i] != ' ' && str[i] != '\0');
      if ((tab[count] = malloc(i + 1)) == NULL)
	return (NULL);
      while (++j < i && (tab[count][j] = str[j]));
      tab[count][j] = 0;
      str += (i + 1);
    }
  tab[count] = NULL;
  return (tab);
}
