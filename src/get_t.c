/*
** getTerm.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:46 2017 nicolas djurovic
** Last update Sun Mar 19 14:13:47 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

void			get_term_size(int *c, int *line)
{
  *c = tigetnum("cols");
  *line = tigetnum("lines");
}

int			init_term(const char *term, bool mode)
{
  static struct termios old;
  struct termios	new;

  if (!term && !mode)
    return (write(2, "Unknown term\n", 13), 1);
  if (!mode)
    {
      if (ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
	return (1);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &new) == -1)
	return (1);
      return (0);
    }
  else if (mode && ioctl(0, TCSETS, &old) == -1)
    return (1);
  return (0);
}

char			*getTerm(const char **env)
{
  int			i;

  i = 0;
  while (env[i])
    {
      if (!my_strncmp("TERM=", env[i], 4))
	return ((char *)(env[i] + 5));
      ++i;
    }
  return (NULL);
}
