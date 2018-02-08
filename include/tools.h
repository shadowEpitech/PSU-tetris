/*
** tools.h for  in /home/shadow/tetris/include
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:08:28 2017 nicolas djurovic
** Last update Sun Mar 19 14:09:02 2017 nicolas djurovic
*/

#ifndef	TOOLS_H_
# define TOOLS_H_

# include <unistd.h>
# include "get_next_line.h"

int	my_getnbr(const char *);
int	my_put_nbr(int);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
char	**my_str_to_wordtab(const char *, const int);
int	my_strlen(const char *);
int	my_strcmp(const char *, const char *);
int	my_strncmp(const char *, const char *, int);

#endif	/* !TOOLS_H_ */
