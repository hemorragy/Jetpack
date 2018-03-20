/*
** interpreter.c for interpreter in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/server
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:41:24 2017 Harold BLERIOT
** Last update Mon Jul 17 14:49:06 2017 Harold BLERIOT
*/

#include "server/interpreter.h"

static const t_func	g_func[] =
  {
    {&fct_id, "ID", 2},
    {&fct_map, "MAP", 3},
    {&fct_ready, "READY", 5},
    {&fct_fire, "FIRE", 4},
    {NULL, NULL, 0}
  };

static void	fun_comp(char *full_cmd, t_serv_info *srv, t_cli *client)
{
  int		i;

  i = 0;
  while (full_cmd && g_func[i].cmp)
    {
      if (!strncmp(full_cmd, g_func[i].cmp, g_func[i].len))
	return (g_func[i].fct(cut_cmd(full_cmd, ' '), srv, client));
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

void		interpreter(t_serv_info *srv, t_cli *client)
{
  char		*cli_input;
  char		*tk_buff;
  size_t	it;
  size_t	i;

  i = 0;
  cli_input = cb_read(client->buffer);
  it = cnt_pattern("\n", cli_input);
  tk_buff = cli_input;
  while (i < it)
    {
      fun_comp(strtok(tk_buff, "\n"), srv, client);
      if (tk_buff)
	tk_buff = NULL;
      i += 1;
    }
  free(cli_input);
}
