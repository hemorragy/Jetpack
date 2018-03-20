/*
** base_graph.c for base_graph in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Sun Jul 16 15:40:36 2017 Loïs Antoine
** Last update Tue Jul 18 18:09:10 2017 Loïs Antoine
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>
#include <sys/time.h>
#include "client/graphic.h"
#include "tools/tools.h"
#include "client/client.h"

static void	disp_tab(t_info *info, t_graph *graph)
{
  SDL_FillRect(graph->screen, NULL, SDL_MapRGB(graph->screen->format, 0, 0, 0));
  disp_wall(info, graph);
  disp_object(info, graph);
  disp_adv(info, graph);
  disp_me(info, graph);
  SDL_Flip(graph->screen);
}

static void	set_graph(t_graph *graph, int width, int height)
{
  if (!(graph->screen = SDL_SetVideoMode(width * 20, height * 20,
					 32, SDL_HWSURFACE))
      || !(graph->texture.zapp[0] = IMG_Load("srcs/img/zapper_solo.png"))
      || !(graph->texture.zapp[1] = IMG_Load("srcs/img/zapper_solo2.png"))
      || !(graph->texture.zapp[2] = IMG_Load("srcs/img/zapper_solo3.png"))
      || !(graph->texture.wall = IMG_Load("srcs/img/wall.png"))
      || !(graph->texture.coins[0] = IMG_Load("srcs/img/coins.png"))
      || !(graph->texture.coins[1] = IMG_Load("srcs/img/coins2.png"))
      || !(graph->texture.coins[2] = IMG_Load("srcs/img/coins3.png"))
      || !(graph->texture.coins[3] = IMG_Load("srcs/img/coins4.png"))
      || !(graph->texture.coins[4] = IMG_Load("srcs/img/coins5.png"))
      || !(graph->texture.coins[5] = IMG_Load("srcs/img/coins6.png"))
      || !(graph->texture.player[0] = IMG_Load("srcs/img/fire_off.png"))
      || !(graph->texture.player[1] = IMG_Load("srcs/img/fire_on.png"))
      || !(graph->texture.player[2] = IMG_Load("srcs/img/at_ground.png"))
      || !(graph->texture.player[3] = IMG_Load("srcs/img/at_ground2.png"))
      || !(graph->texture.player[4] = IMG_Load("srcs/img/adv_player.png")))
    error("Fail loading texture");
}

static void	manage_event(t_graph *graph, int *go_on, t_info *info)
{
  while (SDL_PollEvent(&graph->event) && *go_on)
    {
      if (graph->event.type == SDL_QUIT ||
	  (graph->event.type == SDL_KEYDOWN
	   && graph->event.key.keysym.sym == SDLK_ESCAPE))
	*go_on = 0;
      if (graph->event.type == SDL_KEYDOWN
	  && graph->event.key.keysym.sym == SDLK_SPACE)
	info->client[0].fire = 1;
      if (graph->event.type == SDL_KEYUP
	  && graph->event.key.keysym.sym == SDLK_SPACE)
	info->client[0].fire = 0;
    }
}

void		graphic_base(t_info *info)
{
  t_graph	graph;
  int		go_on;

  graph.screen = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  set_graph(&graph, info->width, info->height);
  SDL_WM_SetIcon(IMG_Load("../img/running1.png"), NULL);
  SDL_WM_SetCaption("JetPack v1.0", NULL);
  disp_tab(info, &graph);
  go_on = 1;
  while (go_on)
    {
      manage_event(&graph, &go_on, info);
      disp_tab(info, &graph);
    }
  SDL_Quit();
}
