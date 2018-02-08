/*
** my_put_nbr.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:14:52 2017 nicolas djurovic
** Last update Sun Mar 19 14:14:55 2017 nicolas djurovic
*/

#include "tools.h"

void	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(const char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  my_putstr("-2147483648");
	  return (11);
	}
      my_putchar('-');
      i++;
      nb = -nb;
    }
  if (nb >= 10)
    i += my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (i);
}
