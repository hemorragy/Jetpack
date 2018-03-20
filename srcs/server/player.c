/*
** player.c for player in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 10:20:31 2017 Harold BLERIOT
** Last update Wed Jul 19 15:36:11 2017 Loïs Antoine
*/

#include <stdbool.h>
#include "server/server.h"
#include "tools/tools.h"

t_player	*player_init(int x, int y)
{
  t_player	*player;

  if(!(player = malloc(sizeof(t_player))))
    mem_error();
  player->is_ready = false;
  player->jet.on_fire = false;
  player->jet.fall = 1.0;
  player->x = x;
  player->y = y;
  player->coins = 0;
  return (player);
}

static bool	player_compare(t_serv_info *srv, t_cli *clients)
{
  int		x;
  int		y;
  t_cli		*tmp;

  tmp = clients;
  while (tmp)
    {
      x = ((int)tmp->player->x + 0.5 > tmp->player->x
	   ? (int)tmp->player->x : (int)tmp->player->x + 1);
      y = ((int)tmp->player->y + 0.5 > tmp->player->y
	   ? (int)tmp->player->y : (int)tmp->player->y + 1);
      if (!(srv->map[y][x] != 'e' && srv->map[y][x + 1] != 'e'
	    && (y + 1 >= srv->map_height || srv->map[y + 1][x] != 'e')))
	return (false);
      tmp = tmp->next;
    }
  return (true);
}

void		player_loose(t_serv_info *srv, t_cli *client)
{
  char		msg[16];
  t_cli		*player;

  player = srv->clients;
  if (player_compare(srv, player))
    player_end(srv);
  while (player && player == client)
    player = player->next;
  sprintf(msg, "FINISH %d\n", player->socket);
  send_to_all(msg, srv->clients);
  shutdown(srv->socket, SHUT_RDWR);
  close(srv->socket);
  exit(0);
}

void		player_end(t_serv_info *srv)
{
  bool		neutral;
  char		msg[16];
  t_cli		*winner;
  t_cli		*tmp;

  neutral = false;
  tmp = srv->clients->next;
  winner = srv->clients;
  while (tmp)
    {
      if (winner->player->coins < tmp->player->coins)
	winner = tmp;
      else if (winner->player->coins == tmp->player->coins)
	neutral = true;
      tmp = tmp->next;
    }
  if (neutral)
    send_to_all("FINISH -1\n", srv->clients);
  else
    {
      sprintf(msg, "FINISH %d\n", winner->socket);
      send_to_all(msg, srv->clients);
    }
  shutdown(srv->socket, SHUT_RDWR);
  close(srv->socket);
  exit(0);
}
