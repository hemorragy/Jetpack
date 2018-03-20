/*
** graphic.h for graphic in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016/srcs/client
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Mon Jul 17 14:01:20 2017 Loïs Antoine
** Last update Tue Jul 18 16:09:42 2017 Loïs Antoine
*/

#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include <SDL/SDL.h>
# include "client/client.h"

typedef struct	s_texture
{
  SDL_Surface	*wall;
  SDL_Surface	*zapp[3];
  SDL_Surface	*player[5];
  SDL_Surface	*coins[6];
}		t_texture;

typedef struct	s_graph
{
  SDL_Event	event;
  SDL_Surface	*screen;
  t_texture	texture;
}		t_graph;

void	graphic_base(t_info *);
void	disp_object(t_info *, t_graph *);
void	disp_wall(t_info *, t_graph *);
void	disp_adv(t_info *, t_graph *);
void	disp_me(t_info *, t_graph *);
int	choose_changes(int, int);

#endif /* !GRAPHIC_H_ */
