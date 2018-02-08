/*
** my_getnbr.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:14:34 2017 nicolas djurovic
** Last update Sun Mar 19 14:14:37 2017 nicolas djurovic
*/

int	my_getnbr(const char *str)
{
  int	i;
  int	j;
  long	b;

  i = 0;
  j = 1;
  b = 0;
  if (!str)
    return (0);
  while (str[i] == 43 || str[i] == 45)
    {
      if (str[i] == 45)
	j = -j;
      ++i;
    }
  str += i;
  i = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      b = b * 10;
      b = b + str[i] - 48;
      ++i;
    }
  return ((int)(j * b));
}
