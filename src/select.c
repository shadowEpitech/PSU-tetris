/*
** select.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:16:43 2017 nicolas djurovic
** Last update Sun Mar 19 14:16:44 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

event		selector_event(void)
{
  event		arr;

  if ((arr = malloc(sizeof(int *) * (6))) == NULL)
    return (NULL);
  arr[LEFT] = &key_left_event;
  arr[RIGHT] = &key_right_event;
  arr[DROP] = &key_drop_event;
  arr[TURN] = &key_turn_event;
  arr[PAUSE] = &key_pause_event;
  arr[QUIT] = &key_quit_event;
  return (arr);
}

int		error_arg(t_game *game, char **argv, bool mode)
{
  (void)game;
  (void)mode;
  --argv;
  write(1, "Usage: ", 7);
  write(1, argv[0], my_strlen(argv[0]));
  write(1, " [options]\n", 11);
  return (1);
}

void		set_actions(ptrtab arr)
{
  arr[0] = &help_arg;
  arr[1] = &level_arg;
  arr[2] = &level_arg;
  arr[3] = &key_left_arg;
  arr[4] = &key_left_arg;
  arr[5] = &key_right_arg;
  arr[6] = &key_right_arg;
  arr[7] = &key_turn_arg;
  arr[8] = &key_turn_arg;
  arr[9] = &key_drop_arg;
  arr[10] = &key_drop_arg;
  arr[11] = &key_quit_arg;
  arr[12] = &key_quit_arg;
  arr[13] = &key_pause_arg;
  arr[14] = &key_pause_arg;
  arr[15] = &size_arg;
  arr[16] = &next_arg;
  arr[17] = &next_arg;
  arr[18] = &debug_arg;
  arr[19] = &debug_arg;
  arr[20] = &error_arg;
}

ptrtab		selector(void)
{
  ptrtab	arr;

  if ((arr = malloc(sizeof(int *) * (NB_ARGS + 1))) == NULL)
    return (NULL);
  set_actions(arr);
  return (arr);
}
