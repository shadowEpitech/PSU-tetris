/*
** pause.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:16:07 2017 nicolas djurovic
** Last update Sun Mar 19 14:16:08 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

void		checkPause(bool *running, char **keys, WINDOW *score,
			   time_t *start)
{
  time_t	elapsed;
  char		buff[BUFF_SIZE];

  if (!*(running))
    {
      elapsed = time(NULL);
      mvwprintw(score, 7, 2, "Game is paused !");
      wrefresh(score);
    }
  while (!(*running))
    {
      my_memset(buff, 0, BUFF_SIZE);
      read(0, buff, BUFF_SIZE - 1);
      if (!my_strncmp(buff, keys[PAUSE], my_strlen(buff) + 1))
	{
	  *running = true;
	  *start += (time(NULL) - elapsed);
	  wclear(score);
	}
      usleep(100);
    }
}
