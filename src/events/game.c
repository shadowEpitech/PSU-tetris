/*
** game.c for  in /home/shadow/tetris/src/events
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:13:17 2017 nicolas djurovic
** Last update Sun Mar 19 14:13:18 2017 nicolas djurovic
*/

#include "tetris.h"

int	key_quit_event(t_game *game)
{
  (void) game;
  return (2);
}

int	key_pause_event(t_game *game)
{
  game->running = ((game->running) ? false : true);
  return (0);
}
