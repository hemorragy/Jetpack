/*
** fct_id.c for fct_id in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Mon Jul 17 14:57:46 2017 Harold BLERIOT
** Last update Tue Jul 18 11:18:14 2017 Harold BLERIOT
*/

#include "client/client.h"

void		fct_id(char *cmd, t_info *info)
{
  int		i;
  size_t	id;

  i = -1;
  while (cmd[++i])
    if (!(cmd[i] >= '0' && cmd[i] <= '9'))
      error("Error: id function");
  sscanf(cmd, "%zu", &id);
  info->client[0].id = id;
}
