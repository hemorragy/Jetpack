/*
** fct_map.c for fct_map in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Mon Jul 17 14:57:46 2017 Harold BLERIOT
** Last update Tue Jul 18 11:03:21 2017 Harold BLERIOT
*/

#include "client/client.h"

static char	**setmap(char *str, size_t h, size_t w)
{
  size_t	i;
  size_t	x;
  size_t	y;
  char		**map;

  i = 0;
  y = 0;
  if (strlen(str) != h * w || !(map = malloc(sizeof(char *) * (h + 1))))
    error("Error: map loading");
  while (y < h && str[i])
    {
      x = 0;
      if (!(map[y] = malloc(sizeof(char) * (w + 1))))
	error("Error: map loading");
      while (x < w && str[i])
	if (!(str[i] == 'c' || str[i] == '_' || str[i] == 'e'))
	  error("Error: map loading");
	else
	  map[y][x++] = str[i++];
      map[y++][x] = 0;
    }
  map[y] = NULL;
  return (map);
}

void		fct_map(char *cmd, t_info *info)
{
  int		i;
  char		**arg;

  i = 0;
  arg = strtowtab(cmd, " ");
  while (arg[i])
    ++i;
  if (i != 3)
    error("Error: map loading");
  sscanf(arg[0], "%zu", &info->width);
  sscanf(arg[1], "%zu", &info->height);
  info->map = setmap(arg[2], info->height, info->width);
  sender("READY\n", info->fd);
}
