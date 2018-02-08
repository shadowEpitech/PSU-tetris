/*
** debug.c for  in /home/shadow/tetris/src/args
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:10:05 2017 nicolas djurovic
** Last update Sun Mar 19 14:10:05 2017 nicolas djurovic
*/

#include "tetris.h"

int	debug_arg(t_game *game, char **argv, bool mode)
{
  (void)mode;
  ++argv;
  game->debug = true;
  return (0);
}
