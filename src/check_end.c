/*
** check_end.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:11:51 2017 nicolas djurovic
** Last update Sun Mar 19 14:11:52 2017 nicolas djurovic
*/

#include "tetris.h"

int	check_end(t_game *game)
{
  if (game->end)
    return (1);
  return (0);
}
