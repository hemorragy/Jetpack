/*
** circular_buffer.h for circular_buffer in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:36:37 2017 Harold BLERIOT
** Last update Tue Jul 18 18:52:56 2017 Harold BLERIOT
*/


#ifndef CIRCULAR_BUFFER_H_
# define CIRCULAR_BUFFER_H_

# include "tools/tools.h"

# define BUFF_SIZE 2048

typedef struct	s_cb
{
  int		free_space;
  char		c_buff[BUFF_SIZE];
  size_t	r_buff;
  size_t	w_buff;
}		t_cb;

t_cb		*cb_init();
int		cb_get_free_space(t_cb *buff);
void		cb_write(char *str, t_cb *buff);
void		cb_write_one(char str, t_cb *buff);
char		*cb_read(t_cb *buff);
char		cb_at(int pos, t_cb *buff);
void		cb_write_one(char c, t_cb *buff);
void		cb_delete_last(t_cb *buff);

#endif /* !CIRCULAR_BUFFER_H_ */
