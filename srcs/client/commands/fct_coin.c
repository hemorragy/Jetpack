/*
** fct_coin.c for fct_coin in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Mon Jul 17 14:56:35 2017 Harold BLERIOT
** Last update Tue Jul 18 19:13:07 2017 Harold BLERIOT
*/

#include "client/client.h"

void		fct_coin_tool(t_info *info)
{
  int		i;
  int		x;
  int		y;

  i = 0;
  while (info->is_start && i < 2)
    {
      x = ((int)info->client[i].x + 0.5 > info->client[i].x
	   ? (int)info->client[i].x : (int)info->client[i].x + 1);
      y = ((int)info->client[i].y + 0.5 > info->client[i].y
	   ? (int)info->client[i].y : (int)info->client[i].y + 1);
      if (info->map[y][x] == 'c')
	{
	  info->client[i].coins += 1;
	  info->map[y][x] = '_';
	}
      i += 1;
    }
}

void		fct_coin(char *cmd, t_info *info)
{
  int		i;
  size_t	x;
  size_t	y;
  size_t	id;
  char		**arg;

  i = 0;
  arg = strtowtab(cmd, " ");
  while (arg[i])
    ++i;
  if (i != 3)
    error("Error: coin function");
  sscanf(arg[0], "%zu", &id);
  sscanf(arg[1], "%zu", &x);
  sscanf(arg[2], "%zu", &y);
  y = info->height - y - 1;
  if (x >= info->width || y >= info->height || info->map[y][x] == 'e')
    error("Error: coin function");
  if (info->map[y][x] == 'c')
    {
      info->map[y][x] = '_';
      i = (id == info->client[0].id ? 0 : 1);
      info->client[i].coins += 1;
    }
}
