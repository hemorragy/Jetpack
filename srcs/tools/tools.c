/*
** tools.c for tools in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:39:56 2017 Harold BLERIOT
** Last update Fri Jul 14 11:54:04 2017 Harold BLERIOT
*/


#include "tools/tools.h"

int	error(char *msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(84);
}

void	*mem_error()
{
  fprintf(stderr, "%s\n", "Memory exceeded.");
  return (NULL);
}

void			canon_mod(int enabled)
{
  struct termios	term;

  tcgetattr(STDIN_FILENO, &term);
  if (enabled)
    {
      term.c_lflag &= ~ICANON;
      term.c_lflag &= ~ECHO;
      term.c_cc[VMIN] = 1;
    }
  else
    {
      term.c_lflag |= ICANON;
      term.c_lflag |= ECHO;
    }
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
