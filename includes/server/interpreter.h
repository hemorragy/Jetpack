/*
** interpreter.h for interpreter in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:34:45 2017 Harold BLERIOT
** Last update Thu Jul 13 17:38:08 2017 Loïs Antoine
*/

#ifndef INTERPRETER_H_
# define INTERPRETER_H_

#include "server/server.h"

typedef struct	s_func
{
  void		(*fct)(char *cmd, t_serv_info *srv, t_cli *client);
  char		*cmp;
  size_t	len;
}		t_func;

/* COMMAND'S FUNCTIONS */
void		fct_id(char *cmd, t_serv_info *srv, t_cli *client);
void		fct_map(char *cmd, t_serv_info *srv, t_cli *client);
void		fct_ready(char *cmd, t_serv_info *srv, t_cli *client);
void		fct_fire(char *cmd, t_serv_info *srv, t_cli *client);

/* INTERPRETER */
void		interpreter(t_serv_info *srv, t_cli *client);

#endif /* !INTERPRETER_H_ */
