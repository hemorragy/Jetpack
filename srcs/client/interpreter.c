/*
** interpreter.c for interpreter in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016
**
** Made by Harold BLERIOT
** Login   <blerio_h@HB-EliteBook>
**
** Started on  Mon Jul 17 14:44:17 2017 Harold BLERIOT
** Last update Tue Jul 18 18:45:12 2017 Loïs Antoine
*/

#include "client/client.h"

static const t_func	g_func[] =
  {
    {&fct_start, "START", 5},
    {&fct_player, "PLAYER", 6},
    {&fct_coin, "COIN", 4},
    {&fct_finish, "FINISH", 6},
    {&fct_map, "MAP", 3},
    {&fct_id, "ID", 2},
    {NULL, NULL, 0}
  };

static void	fun_comp(char *full_cmd, t_info *info)
{
  int		i;

  i = 0;
  while (full_cmd && g_func[i].cmp)
    {
      if (!strncmp(full_cmd, g_func[i].cmp, g_func[i].len))
	return (g_func[i].fct(cut_cmd(full_cmd, ' '), info));
      i += 1;
    }
}

static size_t	cnt_pattern(char *srch, char *str)
{
  char		*ret;
  int		nb;

  nb = 0;
  ret = str;
  while ((ret = strstr(ret, srch)))
    {
      ret += 1;
      nb += 1;
    }
  return (nb);
}

void		interpreter(t_info *info, t_cb *cb_buffer)
{
  char		*input;
  char		*tk_buf;
  size_t	it;
  size_t	i;

  i = 0;
  input = cb_read(cb_buffer);
  it = cnt_pattern("\n", input);
  tk_buf = input;
  while (i < it)
    {
      fun_comp(strtok(tk_buf, "\n"), info);
      if (tk_buf)
	tk_buf = NULL;
      i += 1;
    }
  free(input);
}
