/*
** cut_cmd.c for cut_cmd in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:39:18 2017 Harold BLERIOT
** Last update Thu Jul 13 15:39:19 2017 Harold BLERIOT
*/


char	*cut_cmd(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != c)
    i += 1;
  return (str + i + 1);
}
