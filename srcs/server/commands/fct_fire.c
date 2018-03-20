/*
** fct_fire.c for fct_fire in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server/commands
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 10:12:39 2017 Harold BLERIOT
** Last update Sat Jul 15 15:45:11 2017 Loïs Antoine
*/

#include "server/server.h"
#include "server/interpreter.h"

void	fct_fire(char *cmd, t_serv_info *srv, t_cli *client)
{
  (void)srv;
  if (!client->player)
    mem_error();
  if (strlen(cmd) == 1 && cmd[0] == '0')
    {
      client->player->jet.on_fire = false;
      clock_gettime(CLOCK_MONOTONIC_RAW, &client->player->jet.t);
      client->player->jet.mult = 0;
    }
  else if (strlen(cmd) == 1 && cmd[0] == '1')
    {
      client->player->jet.on_fire = true;
      clock_gettime(CLOCK_MONOTONIC_RAW, &client->player->jet.t);
      client->player->jet.mult = 0;
    }
  else
    error("Wrong argument for FIRE\n");
}
