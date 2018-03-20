/*
** player.h for player in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Fri Jul 14 10:14:54 2017 Harold BLERIOT
** Last update Sun Jul 16 12:05:14 2017 Harold BLERIOT
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include "server/server.h"

typedef struct		s_jet
{
  bool			on_fire;
  struct timespec	t;
  float			fall;
  float			mult;
}			t_jet;

typedef struct		s_player
{
  bool			is_ready;
  float			x;
  float			y;
  size_t		coins;
  t_jet			jet;
}			t_player;

t_player		*player_init(int x, int y);
void			player_loose(t_serv_info *srv, t_cli *client);
void			player_end(t_serv_info *srv);

#endif /* !PLAYER_H_ */
