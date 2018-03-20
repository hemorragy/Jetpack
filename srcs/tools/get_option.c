/*
** get_option.c for get_option in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016
**
** Made by Loïs Antoine
** Login   <antoin_g@pc-antoin_g>
**
** Started on  Fri Jul 14 10:06:20 2017 Loïs Antoine
** Last update Fri Jul 14 12:36:32 2017 Loïs Antoine
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

static bool	is_opt(const char *str, const char *opts)
{
  int		i;

  i = 0;
  if (strlen(str) == 2 && str[0] == '-')
    {
      while (opts[i])
	{
	  if (index(str, opts[i]))
	    {
	    return (true);
	    }
	    ++i;
	}
    }
  return (false);
}

static int	test_opt(const char **tab, const char *str, int i[2], int good)
{
  bool		nans;
  bool		pans;

  nans = is_opt(tab[i[0]], str);
  pans = (!i[0]) ? false : is_opt(tab[i[0] - 1], str);
  if (nans && !pans && !good && i[0] + 1 < i[1])
    return (tab[i[0]][1]);
  else if (nans && !pans && i[0] + 1 < i[1])
    return (-2);
  if (strlen(tab[i[0]]) == 2 && tab[i[0]][0] == '-' && !nans && !pans)
    {
      printf("./server %s is not a valid option\n", tab[i[0]]);
      return (-1);
    }
  return (0);
}

char		get_options(int size, const char **tab,
			    const char *str, int *next)
{
  static int	pos = 0;
  int		count;
  int		ret;
  int		to_send[2];

  to_send[0] = 0;
  to_send[1] = size;
  count = 1;
  ++pos;
  while (to_send[0] < size)
    {
      ret = test_opt(tab, str, to_send, pos - count);
      if (ret == -2)
	++count;
      else if (ret)
	{
	  if (ret > 0)
	    *next = to_send[0] + 1;
	  return (ret);
	}
      ++to_send[0];
    }
  return (-1);
}
