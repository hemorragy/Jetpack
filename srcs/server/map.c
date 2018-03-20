/*
** map.c for map in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 11:14:14 2017 Harold BLERIOT
** Last update Fri Jul 14 14:29:04 2017 Loïs Antoine
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "tools/tools.h"
#include "tools/get_next_line.h"

static void	map_line_check(char *line, int width)
{
  int		i;

  i = -1;
  if (width == 0 || (int)strlen(line) != width)
    error("Error <Map>: Bad width\n");
  while (line[++i])
    if (!(line[i] == 'c' || line[i] == '_' || line[i] == 'e'))
      error("Error <Map>: Wrong character\n");
}

char		**map_init(char *map_path, int *w, int *h)
{
  int		i;
  int		fd;
  char		*line;
  char		**map;

  i = 0;
  *w = -1;
  if ((fd = open(map_path, O_RDONLY)) == -1)
    error("Error <Map>:  No such file\n");
  if (!(map = malloc(sizeof(char *) * 1)))
    mem_error();
  while ((line = get_next_line(fd)))
    {
      if (*w == -1)
	*w = strlen(line);
      map_line_check(line, *w);
      map[i++] = line;
      map = realloc(map, sizeof(char *) * (i + 1));
    }
  map[i] = NULL;
  *h = i;
  if (i == 0)
    error("Error <Map>: Empty file\n");
  close(fd);
  return (map);
}
