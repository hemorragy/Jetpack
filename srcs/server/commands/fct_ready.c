/*
** fct_ready.c for fct_ready in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server/commands
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 10:12:01 2017 Harold BLERIOT
** Last update Sat Jul 15 15:44:55 2017 Loïs Antoine
*/

#include "server/server.h"
#include "server/interpreter.h"

static void	send_start(t_serv_info *srv)
{
  t_cli		*tmp;

  tmp = srv->clients;
  while (tmp)
    {
      clock_gettime(CLOCK_MONOTONIC_RAW, &tmp->player->jet.t);
      tmp->player->jet.mult = 0;
      sender("START\n", tmp->socket);
      tmp = tmp->next;
    }
}

void		fct_ready(char *cmd, t_serv_info *srv, t_cli *client)
{
  int		i;
  t_cli		*tmp;

  (void)cmd;
  (void)srv;
  i = 0;
  if (!client->player)
    mem_error();
  client->player->is_ready = true;
  tmp = srv->clients;
  while (tmp)
    {
      ++i;
      if (tmp->player->is_ready == false)
	return;
      tmp = tmp->next;
    }
  if (i >= 2)
    {
      srv->is_start = true;
      send_start(srv);
      clock_gettime(CLOCK_MONOTONIC_RAW, &srv->start_time);
    }
}
