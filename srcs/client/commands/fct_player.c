/*
** fct_player.c for fct_player in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
** 
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
** 
** Started on  Mon Jul 17 14:55:24 2017 Harold BLERIOT
** Last update Tue Jul 18 16:24:49 2017 Harold BLERIOT
*/

#include "client/client.h"

void		fct_player(char *cmd, t_info *info)
{
  int		i;
  float		x;
  float		y;
  size_t	id;
  char		**arg;

  i = 0;
  arg = strtowtab(cmd, " ");
  while (arg[i])
    ++i;
  if (i != 4)
    error("Error: player function");
  sscanf(arg[0], "%zu", &id);
  sscanf(arg[1], "%f", &x);
  sscanf(arg[2], "%f", &y);
  if (x >= info->width || info->height - y - 1 >= info->height)
    error("Error: player function");
  i = (info->client[0].id == id ? 0 : 1);
  info->client[i].x = x;
  info->client[i].y = info->height - y - 1;
}
