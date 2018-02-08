/*
** score.c for  in /home/shadow/tetris/src
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:16:37 2017 nicolas djurovic
** Last update Sun Mar 19 14:16:38 2017 nicolas djurovic
*/

#include "tetris.h"

void	display_score(WINDOW *score, t_game *game)
{
  game->highscore = 3600;
  mvwprintw(score, 2, 2, "High Score");
  mvwprintw(score, 2, 19, "%d", game->highscore);
  mvwprintw(score, 3, 2, "Score");
  mvwprintw(score, 3, 19, "%d", game->score);
  mvwprintw(score, 5, 2, "Lines");
  mvwprintw(score, 5, 19, "%d", game->line);
  mvwprintw(score, 6, 2, "Level");
  mvwprintw(score, 6, 19, "%d", game->level);
  mvwprintw(score, 8, 2, "Timer:");
  if (game->time_sec > 9)
    mvwprintw(score, 8, 18, "%d : %d", game->time_min, game->time_sec);
  else
    mvwprintw(score, 8, 18, "%d : 0%d", game->time_min, game->time_sec);
}
