/*
** fct_id.c for fct_id in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server/commands
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 09:55:10 2017 Harold BLERIOT
** Last update Fri Jul 14 10:14:17 2017 Harold BLERIOT
*/

#include "server/server.h"
#include "server/interpreter.h"

void		fct_id(char *cmd, t_serv_info *srv, t_cli *client)
{
  char		id[10];

  (void)cmd;
  (void)srv;
  sprintf(id, "ID %d\n", client->socket);
  sender(id, client->socket);
}
