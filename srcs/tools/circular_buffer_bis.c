/*
** circular_buffer_bis.c for circular_buffer_bis in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:38:14 2017 Harold BLERIOT
** Last update Thu Jul 13 15:38:29 2017 Harold BLERIOT
*/


#include "tools/circular_buffer.h"

void	cb_write_one(char c, t_cb *buff)
{
  buff->c_buff[buff->w_buff] = c;
  buff->w_buff = (buff->w_buff + 1) % BUFF_SIZE;
}

void	cb_delete_last(t_cb *buff)
{
  if (buff->r_buff == buff->w_buff)
    return;
  if (buff->w_buff == 0)
    buff->w_buff = BUFF_SIZE - 1;
  else
    buff->w_buff -= 1;
}
