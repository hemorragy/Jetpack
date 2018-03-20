/*
** tools.h for tools in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:37:03 2017 Harold BLERIOT
** Last update Fri Jul 14 12:38:18 2017 Loïs Antoine
*/


#ifndef TOOLS_H_
# define TOOLS_H_

# include <unistd.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>

char	**strtowtab(char *raw, char *sep);
int	error(char *msg);
void	*mem_error();
void	canon_mod(int);
char	*cut_cmd(char *str, char c);
char	get_options(int, const char **, const char *, int *);

#endif /* !TOOLS_H_ */
