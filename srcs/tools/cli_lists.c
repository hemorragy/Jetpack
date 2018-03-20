/*
** cli_lists.c for cli_list in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:39:03 2017 Harold BLERIOT
** Last update Thu Jul 13 15:39:03 2017 Harold BLERIOT
*/


#include "tools/lists.h"

void	cli_push_back(t_cli **list, t_cli *new)
{
  t_cli	*tmp;

  if (!new)
    return;
  new->next = NULL;
  if (!(*list))
    {
      *list = new;
      return;
    }
  tmp = *list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  tmp->next = new;
}

void	cli_pop_elem_free(t_cli **list, int socket)
{
  t_cli	*tmp_bis;
  t_cli	*tmp;

  tmp = *list;
  if ((*list)->socket == socket)
    {
      *list = (*list)->next;
      free(tmp);
      return;
    }
  while (tmp && tmp->next)
    {
      if (tmp->next->socket == socket)
	{
	  tmp_bis = tmp->next;
	  tmp->next = tmp->next->next;
	  free(tmp_bis);
	  return;
	}
      tmp = tmp->next;
    }
}

void	cli_pop_elem(t_cli **list, int socket)
{
  t_cli	*tmp;

  tmp = *list;
  if (!tmp)
    return;
  if ((*list)->socket == socket)
    {
      *list = (*list)->next;
      return;
    }
  while (tmp && tmp->next)
    {
      if (tmp->next->socket == socket)
	{
	  tmp->next = tmp->next->next;
	  return;
	}
      tmp = tmp->next;
    }
}

t_cli	*cli_get_elem(t_cli *list, int socket)
{
  while (list)
    if (list->socket == socket)
      return (list);
    else
      list = list->next;
  return (NULL);
}

void	cli_msg_all(t_cli *list, char *msg)
{
  while (list && msg)
    {
      sender(msg, list->socket);
      list = list->next;
    }
}
