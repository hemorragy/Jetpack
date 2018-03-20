/*
** defines.h for 42sh in /home/antoin_g/rendu/Unix/PSU_2015_42sh
**
** Made by Loïs
** Login   <antoin_g@epitech.net>
**
** Started on  Sun Jun  5 23:15:18 2016 Loïs
** Last update Thu Jul 13 15:03:13 2017 Loïs Antoine
*/

#ifndef DEFINES_H_
# define DEFINES_H_

#ifndef READ_SIZE
# define READ_SIZE (256)
#endif /* !READ_SIZE */

typedef struct	s_gnl
{
  int		test;
  char		*line;
}		t_gnl;

char	*get_next_line(int fd);

#endif /* !DEFINES_H_ */
