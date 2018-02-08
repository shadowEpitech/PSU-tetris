/*
** get_next_line.h for  in /home/shadow/tetris/include
** 
** Made by nicolas djurovic
** Login   <shadow@epitech.net>
** 
** Started on  Sun Mar 19 14:06:40 2017 nicolas djurovic
** Last update Sun Mar 19 14:07:50 2017 nicolas djurovic
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#  define READ_SIZE (14)
# endif	/* !READ_SIZE */

# include <unistd.h>
# include <stdlib.h>

int	find(char [], int);
char	*buff_str(char *, char *, char);
char	*my_realloc(char *, int);
char	*get_next_line(const int);
int	my_strlen1(char *);

#endif /* !GET_NEXT_LINE_H_ */
