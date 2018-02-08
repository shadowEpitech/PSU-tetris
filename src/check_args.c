/*
** check_args.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:11:42 2017 nicolas djurovic
** Last update Sun Mar 19 14:11:43 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

char		**set_keys_default(char **key)
{
  int		i;

  if (setupterm(NULL, 0, &i) < 0 ||
      !(key = malloc(sizeof(char *) * (NB_KEYS + 1))))
    return (NULL);
  key[NB_KEYS] = NULL;
  if (!(key[LEFT] = tigetstr("kcub1")) ||
      !(key[RIGHT] = tigetstr("kcuf1")) ||
      !(key[TURN] = tigetstr("kcuu1")) ||
      !(key[DROP] = tigetstr("kcud1")) ||
      !(key[QUIT] = my_strdup("q")) ||
      !(key[PAUSE] = my_strdup(" ")))
    return (NULL);
  return (key);
}

int		game_default(t_game *game)
{
  if (!(game->keys = set_keys_default(game->keys)))
    return (error("Cannot malloc\n"));
  game->level = 1;
  game->next = 0;
  game->line = 0;
  game->highscore = 0;
  game->score = 0;
  game->time_sec = 0;
  game->time_min = 0;
  game->height = 20;
  game->width = 10;
  game->debug = false;
  game->showNext = true;
  game->running = true;
  return (0);
}

char		**args_list(void)
{
  char		**arr;

  if (!(arr = malloc(sizeof(char *) * (NB_ARGS + 1))) ||
      !(arr[0] = my_strdup("--help")) || !(arr[1] = my_strdup("-l")) ||
      !(arr[2] = my_strdup("--level=")) || !(arr[3] = my_strdup("-kl")) ||
      !(arr[4] = my_strdup("--key-left=")) || !(arr[5] = my_strdup("-kr")) ||
      !(arr[6] = my_strdup("--key-right=")) || !(arr[7] = my_strdup("-kt")) ||
      !(arr[8] = my_strdup("--key-turn=")) || !(arr[9] = my_strdup("-kd")) ||
      !(arr[10] = my_strdup("--key-drop=")) || !(arr[11] = my_strdup("-kq")) ||
      !(arr[12] = my_strdup("--key-quit=")) || !(arr[13] = my_strdup("-kp")) ||
      !(arr[14] = my_strdup("--key-pause=")) ||
      !(arr[15] = my_strdup("--map-size=")) || !(arr[16] = my_strdup("-w")) ||
      !(arr[17] = my_strdup("--without-next")) ||
      !(arr[18] = my_strdup("-d")) || !(arr[19] = my_strdup("--debug")))
    return (NULL);
  arr[20] = NULL;
  return (arr);
}

int		parse_args(int argc, char **argv, t_game *game)
{
  ptrtab	arr;
  char		**args;
  int		i;
  bool		mode;

  if (!(arr = selector()) || !(args = args_list()))
    return (1);
  while (--argc > 0 && argv[0] && (i = -1) && (mode = LONG))
    {
      while (++i < NB_ARGS)
	if ((i && !(i & 1) && i < 16) || i == 15)
	  {
	    if (!my_strncmp(args[i], argv[0], my_strlen(args[i]) - 1))
	      break;
	  }
	else if (my_strncmp(args[i], argv[0], my_strlen(args[i])) == 0)
	  {
	    mode = SHORT;
	    break;
	  }
      if (arr[i](game, argv, mode))
	return (free(arr), free2DArray(args), 1);
      argv += ((i && i < 15 && mode == SHORT) ? 2 : 1);
    }
  return (free(arr), free2DArray(args), 0);
}

int		check_args(int argc, char **argv, char **env)
{
  t_game	game;
  char		*ter;
  char		*smkx;

  if (game_default(&game))
    return (error("Cannot initialize game\n"));
  if (!(ter = getTerm((const char **)env)))
    return (freeKeys(game.keys), error("Cannot find info about term\n"));
  if (argc > 1)
    {
      if (parse_args(argc, argv + 1, &game))
	return (freeKeys(game.keys), 1);
    }
  if (!(smkx = tigetstr("smkx")) || putp(smkx) == ERR)
    return (freeKeys(game.keys), 1);
  if (tetris(&game, ter))
    return (init_term(ter, true), freeKeys(game.keys), endwin(), 1);
  return (init_term(ter, true), freeKeys(game.keys), endwin(), 0);
}
