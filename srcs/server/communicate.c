/*
** communicate.c for communicate in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:40:27 2017 Harold BLERIOT
** Last update Fri Jul 14 14:24:18 2017 Loïs Antoine
*/


#include "server/server.h"

void	disconnect(t_cli *client, t_serv_info *srv)
{
  free(client->player);
  srv->index -= 1;
  cli_pop_elem(&srv->clients, client->socket);
}

void	communicate(t_serv_info *srv, t_cli *client)
{
  char	buff[BUFF_SIZE];
  int	rd_count;

  memset(buff, 0, BUFF_SIZE);
  if ((rd_count = recv(client->socket, buff, cb_get_free_space(client->buffer),
		       0)) > 0)
    {
      cb_write(buff, client->buffer);
      if (cb_at(-1, client->buffer) == '\n')
	interpreter(srv, client);
    }
  else
    {
      if (rd_count < 0)
	fprintf(stderr, "Bad I/O operation.\n");
      FD_CLR(client->socket, &srv->srv_select);
      disconnect(client, srv);
    }
}
