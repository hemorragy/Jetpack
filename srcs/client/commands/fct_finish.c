/*
** fct_finish.c for fct_finish in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
** 
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
** 
** Started on  Mon Jul 17 14:56:35 2017 Harold BLERIOT
** Last update Tue Jul 18 11:20:43 2017 Harold BLERIOT
*/

#include "client/client.h"

void		fct_finish(char *cmd, t_info *info)
{
  int		i;
  int		winner;

  i = -1;
  while (cmd[++i])
    if (!(cmd[i] >= '0' && cmd[i] <= '9'))
      error("Error: id function");
  winner = atoi(cmd);
  if (winner == -1)
    printf("DRAW ! Not a loose, not a win\n");
  else if ((size_t)winner == info->client[0].id)
    printf("YEAH ! You are the WINNER !\n");
  else
    printf("Sorry, but you are a looser... Stop play please\n");
  exit(0);
}
