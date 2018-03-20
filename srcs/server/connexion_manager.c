/*
** connexion_manager.c for connexion_manager in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:41:05 2017 Harold BLERIOT
** Last update Tue Jul 18 18:35:02 2017 Loïs Antoine
*/

#include <stdlib.h>
#include "server/server.h"

void		new_client(int *fd_max, t_serv_info *srv)
{
  t_cli		*client;

  if (!(client = malloc(sizeof(t_cli)))
      || (client->socket = accept(srv->socket, NULL, NULL)) < 0
      || srv->index >= MAX_CLIENTS)
    return;
  FD_SET(client->socket, &srv->srv_select);
  if (client->socket > *fd_max)
    *fd_max = client->socket;
  client->buffer = cb_init();
  client->player = player_init(0, (float)srv->map_height / 2.0);
  cli_push_back(&srv->clients, client);
  srv->index += 1;
}

void		sock_watch(int *fd_max, fd_set *fd_list, int *i, t_serv_info *srv)
{
  if (FD_ISSET(*i, fd_list))
    {
      if (*i == srv->socket)
	new_client(fd_max, srv);
      else
	communicate(srv, cli_get_elem(srv->clients, *i));
    }
}

void			serve(t_serv_info *srv)
{
  int			i;
  int			fd_max;
  fd_set		fd_list;
  struct timeval	tv;

  FD_ZERO(&fd_list);
  fd_max = srv->socket;
  while (g_running)
    {
      i = 0;
      tv.tv_sec = 0;
      tv.tv_usec = 4000;
      fd_list = srv->srv_select;
      if (select(fd_max + 1, &fd_list, NULL, NULL, &tv) < 0)
	return;
      while (i <= fd_max)
	{
	  sock_watch(&fd_max, &fd_list, &i, srv);
	  ++i;
	}
      current_time_action(srv);
    }
}
