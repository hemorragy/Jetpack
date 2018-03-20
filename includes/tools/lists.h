/*
** lists.h for lists in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:36:24 2017 Harold BLERIOT
** Last update Thu Jul 13 15:36:39 2017 Harold BLERIOT
*/


#ifndef LISTS_H_
# define LISTS_H_

# include <stdlib.h>

# include "server/server.h"

void	cli_push_back(t_cli **list, t_cli *add);
void	cli_pop_elem(t_cli **list, int socket);
void	cli_pop_elem_free(t_cli **list, int socket);
t_cli	*cli_get_elem(t_cli *list, int socket);
void	cli_msg_all(t_cli *list, char *msg);
void	ch_push_back(t_ch **list, t_ch *add);
void	ch_pop_elem(t_ch **list, char *srch);
void	ch_pop_elem_free(t_ch **list, char *srch);
t_ch	*ch_get_elem(t_ch *list, char *srch);

#endif /* !LISTS_H_ */
