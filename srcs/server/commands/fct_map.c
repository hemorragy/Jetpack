/*
** fct_map.c for fct_map in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server/commands
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 10:05:56 2017 Harold BLERIOT
** Last update Fri Jul 14 16:02:43 2017 Loïs Antoine
*/

#include "server/server.h"
#include "server/interpreter.h"

void	fct_map(char *cmd, t_serv_info *srv, t_cli *client)
{
  (void)cmd;
  int	i;
  char	msg[32];

  i = 0;
  printf("b\n");
  sprintf(msg, "MAP %d %d ", srv->map_width, srv->map_height);
  sender(msg, client->socket);
  while (i < srv->map_height)
    sender(srv->map[i++], client->socket);
  sender("\n", client->socket);
}
