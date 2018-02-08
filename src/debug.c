/*
** debug.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:12:48 2017 nicolas djurovic
** Last update Sun Mar 19 14:12:48 2017 nicolas djurovic
*/

#include "tetris.h"
#include "tools.h"

int	writeKeys(char *str)
{
  int	j;

  j = 0;
  while (str && str[j])
    if (str[j] != ' ' && str[j] != 27 && write(1, &str[j++], 1) < 0)
      return (1);
    else if (str[j] == ' ' && ++j && write(1, "(space)", 7) < 0)
      return (1);
    else if (str[j] == 27 && ++j && write(1, "^E", 2) < 0)
      return (1);
  if (write(1, "\n", 1) < 0)
    return (1);
  return (0);
}

void	showKeys(t_game *game)
{
  if (write(1, "Key Left : ", 11) < 0 ||
      writeKeys(game->keys[LEFT]) < 0 ||
      write(1, "Key Right : ", 12) < 0 ||
      writeKeys(game->keys[RIGHT]) < 0 ||
      write(1, "Key Turn : ", 11) < 0 ||
      writeKeys(game->keys[TURN]) < 0 ||
      write(1, "Key Drop : ", 11) < 0 ||
      writeKeys(game->keys[DROP]) < 0 ||
      write(1, "Key Quit : ", 11) < 0 ||
      writeKeys(game->keys[QUIT]) < 0 ||
      write(1, "Key Pause : ", 12) < 0 ||
      writeKeys(game->keys[PAUSE]) < 0)
    return ;
}

void	showMoreTetri(t_tetri *tetris, int nb)
{
  int	i;
  int	j;

  if (tetris[nb].error && write(1, "Error\n", 6 >= -1))
    return ;
  if (write(1, "Size ", 5) < 0 || my_put_nbr(tetris[nb].height) < 0 ||
      write(1, "*", 1) < 0 || my_put_nbr(tetris[nb].width) < 0 ||
      write(1, " : Color ", 9) < 0 || my_put_nbr(tetris[nb].color) < 0 ||
      write(1, " :\n", 3) < 0)
    return ;
  i = -1;
  while (++i < tetris[nb].height && (j = -1))
    {
      while (tetris[nb].arr[i][++j])
	if (((tetris[nb].arr[i][j] != -1) ? write(1, "*", 1) :
	     write(1, " ", 1)) < 0)
	  return ;
      if (write(1, "\n", 1) < 0)
	return ;
    }
}

void	showTetri(t_tetri *tetris)
{
  int	nb;

  nb = 0;
  while (tetris[nb].color != -1 && ++nb);
  if (write(1, "Tetriminos : ", 13) < 0 || my_put_nbr(nb) < 0 ||
      write(1, "\n", 1) < 0)
    return ;
  nb = 0;
  while (tetris[nb].color != -1)
    {
      if (write(1, "Tetriminos : Name ", 18) < 0 ||
	  write(1, tetris[nb].name, my_strlen(tetris[nb].name)) < 0 ||
	  write(1, " : ", 3) < 0)
	return ;
      showMoreTetri(tetris, nb);
      ++nb;
    }
}

int	debug_mode(t_game *game, t_tetri *tetris, char *term)
{
  char	buff[BUFF_SIZE];

  if (write(1, "*** DEBUG MODE ***\n", 19) < 0)
    return (1);
  showKeys(game);
  if (write(1, "Next : ", 7) < 0 ||
      ((game->showNext) ? write(1, "Yes\n", 4) : write(1, "No\n", 3)) < 0 ||
      write(1, "Level : ", 8) < 0 ||
      my_put_nbr((int)game->level) < 0 || write(1, "\n", 1) < 0 ||
      write(1, "Size : ", 7) < 0 || my_put_nbr(game->height) < 0 ||
      write(1, "*", 1) < 0 || my_put_nbr(game->width) < 0 ||
      write(1, "\n", 1) < 0)
    return (1);
  showTetri(tetris);
  if (write(1, "Press a key to start Tetris\n", 28) < 0)
    return (1);
  if (init_term(term, false))
    return (error("Cannot init term\n"));
  my_memset(buff, 0, BUFF_SIZE);
  while (!buff[0])
    read(0, buff, BUFF_SIZE - 1);
  if (init_term(term, false))
    return (error("Cannot init term\n"));
  return (0);
}
