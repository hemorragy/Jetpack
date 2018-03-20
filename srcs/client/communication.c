/*
** communication.c for communication in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Mon Jul 17 09:59:41 2017 Harold BLERIOT
** Last update Tue Jul 18 19:10:43 2017 Harold BLERIOT
*/

#include "client/client.h"

static bool			g_run = true;

void			sig_handler(int sig)
{
  if (sig == SIGINT)
    g_run = false;
}

static void		communicate(t_info *info, t_cb *cb_buffer)
{
  char	buff[BUFF_SIZE];
  int	rd_count;

  memset(buff, 0, BUFF_SIZE);
  if ((rd_count = recv(info->fd, buff, cb_get_free_space(cb_buffer), 0)) > 0)
    {
      cb_write(buff, cb_buffer);
      if (cb_at(-1, cb_buffer) == '\n')
	interpreter(info, cb_buffer);
    }
  else
    {
      if (rd_count < 0)
	fprintf(stderr, "Bad I/O operation.\n");
      close(info->fd);
      exit(84);
    }
}

static void		is_on_fire(t_info *info)
{
  static bool		on_fire = false;

  if (on_fire != info->client[0].fire)
    {
      on_fire = (!on_fire);
      if (on_fire)
	sender("FIRE 1\n", info->fd);
      else
	sender("FIRE 0\n", info->fd);
    }
}

int			initializator(char *hostname, char *port)
{
  int			fd;
  struct addrinfo	hint;
  struct addrinfo	*all;
  struct sigaction	sig;

  sig.sa_handler = sig_handler;
  sigemptyset(&sig.sa_mask);
  sig.sa_flags = SA_RESTART;
  sigaction(SIGINT, &sig, NULL);
  memset(&hint, 0, sizeof(struct addrinfo));
  hint.ai_family =  AF_INET;
  hint.ai_socktype = SOCK_STREAM;
  if (getaddrinfo(hostname, port, &hint, &all) != 0)
    error("Error: getaddrinfo");
  if ((fd = socket(all->ai_family, all->ai_socktype, all->ai_protocol)) == -1)
    error("Error: socket");
  if (connect(fd, all->ai_addr, all->ai_addrlen) == -1)
    error("Error: connect");
  return (fd);
}

void			*serve(void *arg)
{
  t_info		*info;
  fd_set		read_fd;
  t_cb			*cb_buffer;
  struct timeval	tv;

  info = (t_info*)arg;
  FD_ZERO(&read_fd);
  FD_SET((unsigned int)info->fd, &read_fd);
  cb_buffer = cb_init();
  sender("ID\n", info->fd);
  sender("MAP\n", info->fd);
  while (g_run)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 2000;
      if (select(info->fd + 1, &read_fd, NULL, NULL, &tv) < 0)
	error("Error: select");
      communicate(info, cb_buffer);
      is_on_fire(info);
      fct_coin_tool(info);
    }
  close(info->fd);
  return (NULL);
}
