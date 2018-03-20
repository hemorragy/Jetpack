/*
** init.c for init in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:40:52 2017 Harold BLERIOT
** Last update Sat Jul 15 11:17:10 2017 Loïs Antoine
*/


#include "server/server.h"

int			binder(struct addrinfo *info, int *fd)
{
  int			len;

  len = 0;
  if ((*fd = socket(info->ai_family, info->ai_socktype,
		    info->ai_protocol)) == -1)
    return (0);
  if (setsockopt(*fd, SOL_SOCKET, SO_REUSEADDR, &len, sizeof(len)))
    return (0);
  if (bind(*fd, info->ai_addr, info->ai_addrlen) == -1)
    {
      close(*fd);
      return (0);
    }
  return (1);
}

int			init_socket(char *charPort)
{
  struct addrinfo	info;
  struct addrinfo	*all;
  struct addrinfo	*i;
  int			fd;
  int			check;

  check = 0;
  memset(&info, 0, sizeof(struct addrinfo));
  info.ai_flags = AI_PASSIVE;
  info.ai_family = AF_UNSPEC;
  info.ai_socktype = SOCK_STREAM;
  getaddrinfo(NULL, charPort, &info, &all);
  if (!(i = all))
    error("Unable to getaddrinfo.");
  while (i && !check)
    {
      if (binder(i, &fd))
	check = 1;
      i = i->ai_next;
    }
  !i ? error("Unable to bind ports.") : 0;
  freeaddrinfo(all);
  if (listen(fd, MAX_QUEUE) == -1)
    error("Unable to listen ports.");
  return (fd);
}

void			sig_handler(int sig)
{
  if (sig == SIGINT)
    g_running = 0;
}

t_serv_info		*initializator(int port, char *charPort, t_flags *flags)
{
  struct sigaction	sig;
  t_serv_info		*serv;

  sig.sa_handler = sig_handler;
  sigemptyset(&sig.sa_mask);
  sig.sa_flags = SA_RESTART;
  sigaction(SIGINT, &sig, NULL);
  if (!(serv = malloc(sizeof(t_serv_info))))
    return (mem_error());
  serv->port = port;
  serv->socket = init_socket(charPort);
  serv->clients = NULL;
  serv->index = 0;
  serv->flags = flags;
  serv->map = map_init(flags->map_file, &serv->map_width, &serv->map_height);
  FD_ZERO(&serv->srv_select);
  FD_SET(serv->socket, &serv->srv_select);
  g_running = 1;
  clock_gettime(CLOCK_MONOTONIC_RAW, &serv->start_time);
  return (serv);
}
