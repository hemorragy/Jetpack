/*
** disp_graph.c for disp_graph in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Tue Jul 18 12:03:28 2017 Loïs Antoine
** Last update Tue Jul 18 18:57:49 2017 Loïs Antoine
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>
#include <sys/time.h>
#include "client/graphic.h"

int			choose_changes(int time, int divide)
{
  static struct timeval	base;
  static int		test = 0;
  struct timeval	new;
  long			inter;

  if (!test)
    {
      test = 1;
      gettimeofday(&base, NULL);
    }
  gettimeofday(&new, NULL);
  inter = (new.tv_sec - base.tv_sec) * 1000000 + (new.tv_usec - base.tv_usec);
  return (inter / time % divide);
}

void		disp_object(t_info *info, t_graph *graph)
{
  size_t	x;
  size_t	y;
  SDL_Rect	pos;

  y = 0;
  while (y < info->height)
    {
      x = 0;
      while (x < info->width)
	{
	  pos.x = x * 20;
	  pos.y = y * 20;
	  if (info->map[y][x] == 'c')
	    SDL_BlitSurface(graph->texture.coins[choose_changes(500000, 6)],
			    NULL, graph->screen, &pos);
	  if (info->map[y][x] == 'e')
	    SDL_BlitSurface(graph->texture.zapp[choose_changes(300000, 3)]
			    , NULL, graph->screen, &pos);
	  ++x;
	}
      ++y;
    }
}

void		disp_wall(t_info *info, t_graph *graph)
{
  size_t	x;
  size_t	y;
  SDL_Rect	pos;

  y = 0;
  while (y < info->height)
    {
      x = 0;
      while (x < info->width)
	{
	  pos.x = x * 20;
	  pos.y = y * 20;
	  SDL_BlitSurface(graph->texture.wall, NULL, graph->screen, &pos);
	  ++x;
	}
      ++y;
    }
}

void		disp_adv(t_info *info, t_graph *graph)
{
  SDL_Rect	pos;

  pos.x = info->client[1].x * 20;
  pos.y = ((info->client[1].y > info->height - 1.5)
	   ? info->height - 1.5 : info->client[1].y) * 20;
  SDL_BlitSurface(graph->texture.player[4], NULL, graph->screen, &pos);
}


void		disp_me(t_info *info, t_graph *graph)
{
  SDL_Rect	pos;

  pos.x = info->client[0].x * 20;
  pos.y = ((info->client[0].y > info->height - 1.5)
	   ? info->height - 1.5 : info->client[0].y) * 20;
  if (info->client[0].fire)
    SDL_BlitSurface(graph->texture.player[1], NULL, graph->screen, &pos);
  else
    {
      if (info->client[0].y < info->height - 1.5)
	SDL_BlitSurface(graph->texture.player[0], NULL, graph->screen, &pos);
      else
	SDL_BlitSurface(graph->texture.player[2 + choose_changes(400000, 2)],
			NULL, graph->screen, &pos);
    }
}
