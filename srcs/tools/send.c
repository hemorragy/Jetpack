/*
** send.c for send in /home/blerio_h/Rendu/SYNTHESIS/jetpack2Tek3_2016/srcs/tools
**
** Made by Harold BLERIOT
** Login   <harold.bleriot@epitech.eu>
**
** Started on  Thu Jul 13 15:39:30 2017 Harold BLERIOT
** Last update Sun Jul 16 12:06:57 2017 Harold BLERIOT
*/


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "tools/send.h"

size_t		sender(char *str, int socket)
{
  ssize_t	ret;

  if ((ret = send(socket, str, strlen(str), 0)) < 0)
    {
      fprintf(stderr, "%s\n", "Error when sending data to client.");
      return (0);
    }
  return (ret);
}
