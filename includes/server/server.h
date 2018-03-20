/*
** server.h for server in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:34:36 2017 Harold BLERIOT
** Last update Sun Jul 16 12:03:19 2017 Harold BLERIOT
*/

#ifndef SERVER_H_
# define SERVER_H_

# define _GNU_SOURCE

# define MAX_QUEUE 10
# define MAX_CLIENTS 50
# define MAX_NICK 50

# include <time.h>
# include <netdb.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <getopt.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <arpa/inet.h>

int			g_running;

typedef struct s_cli		t_cli;
typedef struct s_flags		t_flags;
typedef struct s_ch		t_ch;
typedef struct s_serv_info	t_serv_info;
typedef struct s_graphic	t_graphic;

# include "server/interpreter.h"
# include "tools/tools.h"
# include "tools/lists.h"
# include "tools/send.h"
# include "tools/circular_buffer.h"
# include "server/player.h"

struct				s_cli
{
  int				socket;
  t_cb				*buffer;
  t_player			*player;
  struct s_cli			*next;
};

struct				s_flags
{
  int				verbose;
  int				gravity;
  char				*map_file;
};

struct				s_serv_info
{
  int				port;
  int				socket;
  int				map_width;
  int				map_height;
  bool				is_start;
  t_cli				*clients;
  size_t			index;
  fd_set			srv_select;
  t_flags			*flags;
  char				**map;
  struct timespec		start_time;
};

void				disconnect(t_cli *user, t_serv_info *srv);
void				communicate(t_serv_info *srv, t_cli *client);
void				serve(t_serv_info *srv);
int				error(char *msg);
void				*mem_error();
int				init_socket(char *charPort);
t_serv_info			*initializator(int port, char *charPort,
					       t_flags *);
void				sock_watch(int *fd_max, fd_set *fd_list,
					   int *i, t_serv_info *srv);
int				getargg(char **argv, char opt, int optind,
					t_flags *flags);
int				getargm(char **argv, char opt, int optind,
					t_flags *flags);
int				getargv(char **argv, char opt, int optind,
					t_flags *flags);
char				**map_init(char *, int *, int *);
void				current_time_action(t_serv_info *);
void				send_to_all(char *msg, t_cli *clients);

#endif /* !SERVER_H_ */
