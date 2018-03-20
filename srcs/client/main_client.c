/*
1;4205;0c** main_client.c for main_client in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Thu Jul 13 16:09:13 2017 Loïs Antoine
** Last update Tue Jul 18 18:09:38 2017 Loïs Antoine
*/

#include <pthread.h>
#include <unistd.h>
#include "client/client.h"
#include "client/graphic.h"

static void	usage()
{
  fprintf(stderr, "./clientJ2T3 -h <ip> -p <port>\n");
  exit(84);
}


static void	find_arg(int ac, char **av, t_info *info)
{
  char		opt;
  char		*ip;
  char		*port;

  ip = NULL;
  port = NULL;
  while ((opt = getopt(ac, av, "hp")) != -1)
    {
      if (opt == 'h')
	ip = av[optind];
      else if (opt == 'p')
	port = av[optind];
    }
  if (!ip || !port)
    usage();
 info->fd = initializator(ip, port);
}

int		main(int ac, char **av)
{
  t_info	info;
  pthread_t	thread;

  info.is_start = false;
  info.client[0].fire = false;
  find_arg(ac, av, &info);
  pthread_create(&thread, NULL, serve, &info);
  while (!info.is_start);
  graphic_base(&info);
  return (0);
}
