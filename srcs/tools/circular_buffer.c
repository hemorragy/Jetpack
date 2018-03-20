/*
** circular_buffer.c for circular_buffer in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:38:27 2017 Harold BLERIOT
** Last update Thu Jul 13 15:38:28 2017 Harold BLERIOT
*/


#include "server/server.h"

t_cb	*cb_init()
{
  t_cb	*buff;

  if (!(buff = malloc(sizeof(t_cb))))
    error("Critical memory corruption.");
  memset(buff->c_buff, 0, BUFF_SIZE);
  buff->free_space = BUFF_SIZE;
  buff->r_buff = 0;
  buff->w_buff = 0;
  return (buff);
}

int	cb_get_free_space(t_cb *buff)
{
  if (buff->w_buff >= buff->r_buff)
    return (BUFF_SIZE - (buff->w_buff - buff->r_buff));
  else
    return (buff->r_buff - buff->w_buff);
}

void	cb_write(char *str, t_cb *buff)
{
  int	i;

  i = 0;
  while (str[i])
    {
      buff->c_buff[buff->w_buff] = str[i];
      buff->w_buff = (buff->w_buff + 1) % BUFF_SIZE;
      i += 1;
    }
}

char	*cb_read(t_cb *buff)
{
  char		*ret;
  size_t	end;
  size_t	i;

  i = 0;
  if (buff->w_buff >= buff->r_buff)
    end = buff->w_buff - buff->r_buff;
  else
    end = BUFF_SIZE - (buff->r_buff - buff->w_buff);
  if (!(ret = malloc(sizeof(char) * (end + 1))))
    return (mem_error());
  while (i < end)
    {
      ret[i] = buff->c_buff[buff->r_buff];
      buff->r_buff = (buff->r_buff + 1) % BUFF_SIZE;
      i += 1;
    }
  return (ret);
}

char	cb_at(int pos, t_cb *buff)
{
  if (pos >= 0)
    return (buff->c_buff[(buff->r_buff + pos) % BUFF_SIZE]);
  else
    return (buff->c_buff[(buff->w_buff + pos) % BUFF_SIZE]);
}
