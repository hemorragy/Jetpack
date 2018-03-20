/*
** strtowtab.c for strtowtab in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
** 
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
** 
** Started on  Thu Jul 13 15:39:46 2017 Harold BLERIOT
** Last update Thu Jul 13 15:39:46 2017 Harold BLERIOT
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	count_word(char *in)
{
  int	i;
  int	count;
  int	check;

  i = 0;
  count = 0;
  check = 0;
  while (in && in[i] != '\0')
    {
      if (in[i] != ' ')
	check = 0;
      if (check == 0 && in[i] == ' ')
	{
	  ++count;
	  check = 1;
	}
      ++i;
    }
  return (count + 1);
}

char	**strtowtab(char *raw, char *sep)
{
  char	*raw_tmp;
  char	**tmp;
  char	*token;
  int	i;

  i = 0;
  raw_tmp = NULL;
  if (raw)
    raw_tmp = strdup(raw);
  if (!raw_tmp || !sep || !(tmp =
			    malloc(sizeof(char *) * (count_word(raw_tmp) + 2))))
    return (NULL);
  token = strtok(raw, sep);
  if (token)
    tmp[i++] = strdup(token);
  while ((token = strtok(NULL, sep)))
    tmp[i++] = strdup(token);
  tmp[i] = NULL;
  free(raw_tmp);
  return (tmp);
}
