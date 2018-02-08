/*
** main.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:14:21 2017 nicolas djurovic
** Last update Sun Mar 19 17:55:43 2017 Nelson ANGELIQUE
*/

#include "tetris.h"
#include "tools.h"

void		get_time(t_game *game, time_t *start)
{
  time_t	curr;

  curr = time(NULL) - *start;
  game->time_min = curr / 60;
  game->time_sec = curr % 60;
}

int		initLoop(t_loop *loop, t_game *game, char *term)
{
  if (!(loop->tetri = NULL) && !(loop->next = 0) &&
      (!(loop->events = selector_event()) ||
       !(loop->tetri = load_tetri(loop->tetri, game))))
    return (1);
  if (game->debug && debug_mode(game, loop->tetri, term))
    return (1);
  if (init_game(game))
    return (1);
  if (display1(&loop->win, game, term))
    return (1);
  return (0);
}

int		check_keys(t_loop *loop, t_game *game)
{
  int		check;

  check = read(0, loop->buff, BUFF_SIZE - 1);
  if (check == -1)
    return (free(loop->events), free2DArray(game->arr), endwin(), 1);
  while (++loop->i < UNKNOWN)
    if (!my_strncmp(loop->buff, game->keys[loop->i],
		    my_strlen(loop->buff) + 1))
      {
	if ((loop->check = (loop->events[loop->i](game))) == 1)
	  return (free(loop->events), free2DArray(game->arr), 1);
	else if (loop->check == 2)
	  return (free(loop->events), free2DArray(game->arr), 2);
      }
  return (0);
}

int		tetris(t_game *game, char *term)
{
  t_loop	loop;
  int		timer;
  time_t	start;

  timer = -1;
  if (!initLoop(&loop, game, term) && (start = time(NULL)) != ((time_t) -1) &&
      !add_tetri(loop.tetri, game) && !(game->end = false))
    while (my_memset(loop.buff, 0, BUFF_SIZE), (loop.i = -1), timer += 2,
	   usleep(100), !check_end(game))
      if (get_time(game, &start),
	  display2(&loop.win, &loop.tetri[game->next], game))
	return (freeWin(&loop.win), free(loop.events), free_tetris(loop.tetri),
		endwin(), 1);
      else if ((loop.check = check_keys(&loop, game)) == 1)
	return (freeWin(&loop.win), free_tetris(loop.tetri), 1);
      else if (loop.check == 2)
	return (freeWin(&loop.win), free_tetris(loop.tetri), 0);
      else if (checkPause(&game->running, game->keys, loop.win.score, &start),
	       timer >= CHECK_TIME)
	if (timer = -1, tetri(game))
	  add_tetri(loop.tetri, game);
  return (1);
}

int		main(int argc, char **argv, char **env)
{
  if (!env || check_args(argc, argv, env))
    return (1);
  return (0);
}
