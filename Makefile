##
## Makefile for Makefile in /home/antoin_g/rendu/Synthesis/jetpack2Tek3_2016
##
## Made by Loïs Antoine
## Login   <antoin_g@epitech.net>
##
## Started on  Thu Jul 13 16:00:48 2017 Loïs Antoine
## Last update Tue Jul 18 16:06:06 2017 Loïs Antoine
##

CC	=	gcc -g3

RM	=	rm -rf

CPPFLAGS	+=	 -Iincludes
CFLAGS	+=	-W -Wall -Wextra -Werror

SERVER	=	serverJ2T3

CLIENT	=	clientJ2T3

SRC	=	srcs/

SRCS1	=	$(SRC)server/commands/fct_ready.c \
		$(SRC)server/commands/fct_fire.c \
		$(SRC)server/connexion_manager.c \
		$(SRC)server/commands/fct_map.c \
		$(SRC)server/commands/fct_id.c \
		$(SRC)server/communicate.c \
		$(SRC)server/interpreter.c \
		$(SRC)server/time_action.c \
		$(SRC)server/argsfcts.c \
		$(SRC)server/player.c \
		$(SRC)server/init.c \
		$(SRC)server/main.c \
		$(SRC)server/map.c

OBJS1	=	$(SRCS1:.c=.o)

SRCS2	=	$(SRC)client/commands/fct_finish.c \
		$(SRC)client/commands/fct_player.c \
		$(SRC)client/commands/fct_start.c \
		$(SRC)client/commands/fct_coin.c \
		$(SRC)client/commands/fct_map.c \
		$(SRC)client/commands/fct_id.c \
		$(SRC)client/communication.c \
		$(SRC)client/interpreter.c \
		$(SRC)client/main_client.c \
		$(SRC)client/disp_graph.c \
		$(SRC)client/base_graph.c

OBJS2	=	$(SRCS2:.c=.o)

COM	=	$(SRC)tools/circular_buffer_bis.c \
		$(SRC)tools/circular_buffer.c \
		$(SRC)tools/get_next_line.c \
		$(SRC)tools/get_option.c \
		$(SRC)tools/cli_lists.c \
		$(SRC)tools/strtowtab.c \
		$(SRC)tools/cut_cmd.c \
		$(SRC)tools/tools.c \
		$(SRC)tools/send.c

COBJS	=	$(COM:.c=.o)

all:	server client

server:	$(OBJS1) $(COBJS)
	$(CC) -o $(SERVER) $(OBJS1) $(COBJS)

client:	$(OBJS2) $(COBJS)
	$(CC) -o $(CLIENT) $(OBJS2) $(COBJS) -pthread -lSDL -lSDL_image

clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)
	$(RM) $(COBJS)

fclean: 	clean
		$(RM) $(SERVER)
		$(RM) $(CLIENT)

re:	fclean all

.PHONY:	all clean fclean re
