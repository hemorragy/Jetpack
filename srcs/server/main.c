/*
** main.c for main in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:41:47 2017 Harold BLERIOT
** Last update Tue Jul 18 18:55:42 2017 Harold BLERIOT
*/


#include "server/server.h"

static int	bad_command(char *name)
{
  fprintf(stderr, "USAGE: %s > -p <port> -g <gravity> -m <map>\n", name);
  return (84);
}

static int	findargs(int argc, char **argv, char **charport,
			 t_flags *flags)
{
  char		opt;
  int		check;
  int		port;
  int		next;

  port = 0;
  while ((opt = get_options(argc, (const char **)argv, "pgmv", &next)) != -1)
    {
      check = 0;
      if (opt == 'p')
	{
	  if (!argv[next] || (port = atoi(argv[next])) <= 1
	      || !(*charport = argv[next]))
	    return (error("Port must be a positive number superior to 1."));
	  ++check;
	}
      check += getargg(argv, opt, next, flags);
      check += getargm(argv, opt, next, flags);
      check += getargv(argv, opt, next, flags);
      if (check == 0)
	return (error("Invalid argument."));
    }
  return (port);
}

int		main(int argc, char **argv)
{
  t_flags	flags;
  t_serv_info	*srv;
  int		port;
  char		*charport;

  srand(time(NULL));
  port = 0;
  charport = NULL;
  flags.verbose = 0;
  flags.gravity = 0;
  flags.map_file = NULL;
  port = findargs(argc, argv, &charport, &flags);
  if (!flags.map_file || !port)
    return (bad_command(argv[0]));
  srv = initializator(port, charport, &flags);
  serve(srv);
  shutdown(srv->socket, SHUT_RDWR);
  close(srv->socket);
  return (0);
}
