/*
** my_strlen.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:15:16 2017 nicolas djurovic
** Last update Sun Mar 19 14:15:18 2017 nicolas djurovic
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str && *str != '\0' && (str++) && (++i));
  return (i);
}
