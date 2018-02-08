/*
** tetris.h for  in /home/shadow/tetris/include
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:07:59 2017 nicolas djurovic
** Last update Sun Mar 19 17:45:54 2017 Nelson ANGELIQUE
*/

#ifndef	TETRIS_H_
# define TETRIS_H_
# define NB_ARGS		20
# define NB_KEYS		6
# define MIN_ROW		20
# define MAX_ROW		80
# define MIN_COL		10
# define MAX_COL		80
# define BUFF_SIZE		4096
# define BETWEEN(A, MIN, MAX) \
  (((A) >= (MIN)) ? (((A) <= (MAX)) ? 2 : 0) : 0)
# define TIME(X)		(((X) <= 0) ?  1 : (X))
# define CHECK_TIME		TIME(20 - game->level)

# define _BDS_SOURCE
# define _POSIX_SOURCE
# define _DEFAULT_SOURCE

# include <time.h>
# include <ncurses.h>
# include <curses.h>
# include <term.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <dirent.h>

typedef	enum	e_mode
  {
    SHORT,
    LONG
  }		t_mode;

typedef enum	e_move
  {
    RIGHT_M	= -1,
    VERTICAL_M	= 0,
    LEFT_M	= 1
  }		t_move;

typedef	enum	e_keys
  {
    LEFT,
    RIGHT,
    DROP,
    TURN,
    PAUSE,
    QUIT,
    UNKNOWN
  }		t_keys;

typedef struct	s_window
{
  WINDOW	*title;
  WINDOW	*score;
  WINDOW	*board;
  WINDOW	*next;
}		t_window;

typedef struct	s_tetri
{
  char		**arr;
  char		*name;
  bool		error;
  int		height;
  int		width;
  int		color;
  int		x;
  int		y;
}		t_tetri;

typedef struct	s_time
{
  time_t	count;
  time_t	tick;
  time_t	check;
}		t_time;

typedef struct	s_game
{
  char		level;
  int		next;
  int		line;
  int		score;
  int		highscore;
  int		time_sec;
  int		time_min;
  int		height;
  int		width;
  bool		showNext;
  bool		debug;
  bool		end;
  bool		running;
  int		cur;
  t_tetri	*tetris;
  char		**arr;
  char		**keys;
}		t_game;

typedef struct	s_loop
{
  t_tetri	*tetri;
  t_window	win;
  int		(**events)(t_game *);
  char		buff[BUFF_SIZE];
  int		i;
  int		next;
  int		cur;
  int		check;
}		t_loop;

typedef		int (**ptrtab)(t_game *, char **, bool);
typedef		int (**event)(t_game *);

/*
** ===================================================
**                      TO ORDER
** ===================================================
*/
void		checkPause(bool *, char **, WINDOW *, time_t *);
bool		isOver(t_game *);
int		debug_mode(t_game *, t_tetri *, char *);
void		getTermSize(int *, int *);
void		freeWin(t_window *);
void		free_tetris(t_tetri *);
void		freeKeys(char **);
void		free2DArray(char **);
int		error(const char *);
int		check_file(char *);

/*
** ===================================================
**                       EVENTS
** ===================================================
*/
event		selector_event(void);
int		key_left_event(t_game *);
int		key_right_event(t_game *);
int		key_turn_event(t_game *);
int		key_drop_event(t_game *);
int		key_quit_event(t_game *);
int		key_pause_event(t_game *);

/*
** ===================================================
**                     CHECK ARGS
** ===================================================
*/
int		init_term(const char *, bool);
char		*getTerm(const char **);
ptrtab		selector(void);
int		check_args(int, char **, char **);

/*
** ===================================================
**                       ARGS
** ===================================================
*/
int		getKey(int *, const char *);
int		help_arg(t_game *, char **, bool);
int		level_arg(t_game *, char **, bool);
int		key_left_arg(t_game *, char **, bool);
int		key_right_arg(t_game *, char **, bool);
int		key_turn_arg(t_game *, char **, bool);
int		key_drop_arg(t_game *, char **, bool);
int		key_quit_arg(t_game *, char **, bool);
int		key_pause_arg(t_game *, char **, bool);
int		size_arg(t_game *, char **, bool);
int		next_arg(t_game *, char **, bool);
int		debug_arg(t_game *, char **, bool);
int		error_arg(t_game *, char **, bool);

/*
** ===================================================
**                       LOAD
** ===================================================
*/
char		*cle_name(char *);
void		set_color(t_tetri *);
char		**getNames(DIR *);
t_tetri		*load_tetri(t_tetri *, t_game *);
char		*add_dir_name(char *);
int		fill_tetri(char *, int, int, t_tetri *);
int		get_tetri(int, t_tetri *, char *, t_game *);
int		get_info(char *, t_tetri *, int, t_game *);
t_tetri		*my_realloc_tab(t_tetri *);

/*
** ===================================================
**                       INIT
** ===================================================
*/
int		tetris(t_game *, char *);
int		init_game(t_game *);
int		display1(t_window *, t_game *, char *);
char		**malloc_tab(char **, int, int);
void		my_memset(void *, char, int);
void		pair_color(void);
WINDOW		*create_win2(int, int, int, int);
WINDOW		*create_board(int, int, int, int);
int		create_win(t_window *, t_game *);

/*
** ===================================================
**                      GAME
** ===================================================
*/
int		add_tetri(t_tetri *, t_game *);
int		check_line(t_game *);
int		line_full(t_game *, int);
void		fall_all_tetri(t_game *, int);
int		fall_tetri(t_game *);
int		check_print_tetri(t_tetri *, t_game *, int, int);
int		check_end(t_game *);
void		clean_tetri(t_tetri *, t_game *, int, int);
void		print_tetri(t_tetri *, t_game *, int, int);
int		random_tetri(t_tetri *);
int		copy_tetris(t_tetri *, t_game *);
int		check_rotate(t_tetri *, t_game *, int, int);
char		**rotate(t_tetri *);

/*
** ===================================================
**                      DISPLAY
** ===================================================
*/
int		display2(t_window *, t_tetri *, t_game *);
void		display_score(WINDOW *, t_game *);
void		display_title(WINDOW *);
void		display_interface(t_window *, t_game *);
void		display_board(t_window *, t_tetri *, t_game *);
void		display_tetri(WINDOW *, char **, int);
void		display_next(WINDOW *, t_tetri *);

#endif /* TETRIS_H_ */
