/*
1;4205;0c** time_action.c for time_action in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Sat Jul 15 11:21:19 2017 Loïs Antoine
** Last update Wed Jul 19 15:30:43 2017 Loïs Antoine
*/

#include <time.h>
#include "server/server.h"

static void	move_collision(t_serv_info *srv, t_cli *client)
{
  int		x;
  int		y;
  char		msg[32];

  x = ((int)client->player->x + 0.5 > client->player->x
       ? (int)client->player->x : (int)client->player->x + 1);
  y = ((int)client->player->y + 0.5 > client->player->y
       ? (int)client->player->y : (int)client->player->y + 1);
  if (srv->map[srv->map_height - y - 1][x] == 'c')
    {
      sprintf(msg, "COIN %d %d %d\n", client->socket,
	      x, y);
      client->player->coins += 1;
      send_to_all(msg, srv->clients);
      srv->map[srv->map_height - y - 1][x] = '_';
    }
  else if (srv->map[srv->map_height - y - 1][x] != '_')
    player_loose(srv, client);
}

static void	move_x(t_serv_info *srv)
{
  char		msg[32];
  t_cli		*tmp;

  tmp = srv->clients;
  while (tmp)
    {
      if (tmp->player->x + 1 < srv->map_width)
	{
	  tmp->player->x += 0.02;
	  sprintf(msg, "PLAYER %d %f %f %lu\n", tmp->socket,
		  tmp->player->x, tmp->player->y, tmp->player->coins);
	  move_collision(srv, tmp);
	  send_to_all(msg, srv->clients);
	}
      else
	player_end(srv);
      tmp = tmp->next;
    }
}

static void		move_y(t_serv_info *srv, struct timespec *cur)
{
  char			msg[32];
  t_cli			*tmp;
  float			mult;
  uint64_t		elapsed;

  tmp = srv->clients;
  while (tmp)
    {
      elapsed = (cur->tv_sec - tmp->player->jet.t.tv_sec) * 1000000
	+ (cur->tv_nsec - tmp->player->jet.t.tv_nsec) / 1000;
      if ((float)(elapsed / 100000) > tmp->player->jet.mult)
	{
	  mult = (elapsed * 2) / 1000000.0;
	  if ((tmp->player->jet.on_fire && srv->flags->gravity > 0)
	      || (!tmp->player->jet.on_fire && srv->flags->gravity < 0))
	    tmp->player->y -= (0.008 *
			       ((srv->flags->gravity > 0) ? srv->flags->gravity
				: -srv->flags->gravity) * mult);
	  else if ((!tmp->player->jet.on_fire && srv->flags->gravity > 0)
		   || (tmp->player->jet.on_fire && srv->flags->gravity < 0))
	    tmp->player->y += (0.008 *
			       ((srv->flags->gravity > 0) ? srv->flags->gravity
				: -srv->flags->gravity) * mult);
	  if (tmp->player->y + 0.5 >= srv->map_height)
	    tmp->player->y = srv->map_height - 0.6;
	  if (tmp->player->y < 0)
	    tmp->player->y = 0;
	  tmp->player->jet.mult += 0.02;
	  sprintf(msg, "PLAYER %d %f %f %lu\n", tmp->socket,
		  tmp->player->x, tmp->player->y, tmp->player->coins);
	  move_collision(srv, tmp);
	  send_to_all(msg, srv->clients);
	}
      tmp = tmp->next;
    }
}

void		send_to_all(char *msg, t_cli *clients)
{
  t_cli		*tmp;

  tmp = clients;
  while (tmp)
    {
      sender(msg, tmp->socket);
      tmp = tmp->next;
    }
}

void			current_time_action(t_serv_info *srv)
{
  static float		loopx = 0.0;
  struct timespec	cur;
  uint64_t		elapsed;

  if (srv->is_start)
    {
      clock_gettime(CLOCK_MONOTONIC_RAW, &cur);
      elapsed = (cur.tv_sec - srv->start_time.tv_sec) * 1000000
	+ (cur.tv_nsec - srv->start_time.tv_nsec) / 1000;
      if ((float)(elapsed / 200000) > loopx)
	{
	  move_x(srv);
	  loopx += 0.02;
	}
      move_y(srv, &cur);
    }
}
