/*
** argsfcts.c for argsfcts in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:40:38 2017 Harold BLERIOT
** Last update Wed Jul 19 15:47:32 2017 Loïs Antoine
*/

#include "server/server.h"

int	getargg(char **argv, char opt, int optind, t_flags *flags)
{
  if (opt == 'g')
    {
      if (flags->gravity == 0)
	{
	  if (!argv[optind])
	    return (error("g must be a positive number."));
	  else
	    flags->gravity = atoi(argv[optind]);
	}
      return (1);
    }
  return (0);
}

int	getargm(char **argv, char opt, int optind, t_flags *flags)
{
  if (opt == 'm')
    {
      if (flags->map_file == NULL)
	if (!argv[optind] || !(flags->map_file = strdup(argv[optind])))
	  return (error("Map must be the name of the file"));
      return (1);
    }
  return (0);
}

int	getargv(char **argv, char opt, int optind, t_flags *flags)
{
  if (opt == 'v')
    {
      if (flags->verbose == 0)
	if (argv[optind])
	  flags->verbose = 1;
      return (1);
    }
  return (0);
}
