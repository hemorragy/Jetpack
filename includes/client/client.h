/*
** client.h for client in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Mon Jul 17 10:45:11 2017 Harold BLERIOT
** Last update Tue Jul 18 19:11:06 2017 Harold BLERIOT
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdio.h>
# include <netdb.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/socket.h>

# include "tools/send.h"
# include "tools/tools.h"
# include "tools/circular_buffer.h"

typedef struct s_info		t_info;

typedef struct	s_func
{
  void		(*fct)(char *cmd, t_info *info);
  char		*cmp;
  size_t	len;
}		t_func;

typedef struct	s_player
{
  float		x;
  float		y;
  bool		fire;
  size_t	id;
  size_t	coins;
}		t_player;

struct	s_info
{
  int		fd;
  bool		is_start;
  char		**map;
  size_t	width;
  size_t	height;
  t_player	client[2];
};

void		*serve(void *arg);
int		initializator(char *hostname, char *port);
void		interpreter(t_info *info, t_cb *cb_buffer);

void		fct_start(char *cmd, t_info *info);
void		fct_player(char *cmd, t_info *info);
void		fct_coin(char *cmd, t_info *info);
void		fct_finish(char *cmd, t_info *info);
void		fct_map(char *cmd, t_info *info);
void		fct_id(char *cmd, t_info *info);
void		fct_coin_tool(t_info *info);

#endif /* !CLIENT_H_ */
