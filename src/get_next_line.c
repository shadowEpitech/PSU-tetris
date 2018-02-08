/*
** get_next_line.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:33 2017 nicolas djurovic
** Last update Sun Mar 19 14:13:34 2017 nicolas djurovic
*/

#include "get_next_line.h"

int	my_strlen1(char *str)
{
  int	j;

  j = 0;
  if (str == NULL)
    return (0);
  while (*str)
    {
      str++;
      j++;
    }
  return (j);
}

char	*my_realloc(char *str, int size)
{
  char	*result;
  int	j;
  int	len;

  if (size == 0)
    return (str);
  if (str != NULL)
    {
      len = my_strlen1(str);
      if ((result = malloc(len + size + 1)) == NULL)
	return (NULL);
      j = -1;
      while (++j < len && (result[j] = str[j]));
      result[j] = '\0';
      free(str);
      return (result);
    }
  return (str);
}

int	find(char buff[], int t)
{
  int	i;
  int	res;

  i = 0;
  while (buff[i] != '\0'  && buff[i] != '\n' && (++i));
  if (i > -1 && buff[i] == '\n' && t == 0)
    return (i);
  if (t == 1)
    {
      i++;
      res = 0;
      while (buff[i] != '\0')
	buff[res++] = buff[i++];
      buff[res] = '\0';
      return (i);
    }
  return (-1);
}

char	*buff_str(char *s1, char *s2, char car)
{
  int	k;

  k = -1;
  while (s2[++k] != car)
    s1[k] = s2[k];
  s1[k] = '\0';
  return (s1);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1] = {0};
  char		*res;
  int		c[2];

  if ((c[0] = find(buff, 0)) > -1 &&
      ((res = malloc(sizeof(char) * (c[0] + 1))) != NULL && !(res[0] = 0) &&
       (res = buff_str(res, buff, '\n')) != NULL && find(buff, 1) != -2))
    return (res);
  else if (buff[0])
    {
      if ((res = malloc(sizeof(char) * (my_strlen1(buff) + 1))) == NULL)
	return (NULL);
      res = buff_str(res, buff, '\0');
    }
  else if ((res = malloc(sizeof(char))) == NULL || (res[0] = '\0'))
    return (NULL);
  while (fd >= 0 && (c[1] = read(fd, &buff, READ_SIZE)) > 0 &&
	 !(buff[c[1]] = '\0') && (c[0] = find(buff, 0)) > -2)
    if (c[0] > -1 && (res = my_realloc(res, c[0])) &&
	buff_str(res + my_strlen1(res), buff, '\n') && find(buff, 1) > -1)
      return (res);
    else if ((res = my_realloc(res, c[1])) != NULL)
      buff_str(res + my_strlen1(res), buff, '\0');
  return (NULL);
}
