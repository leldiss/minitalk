# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 12:19:27 by leldiss           #+#    #+#              #
#    Updated: 2022/03/26 19:50:42 by leldiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

FILES_S = ./server.c
FILES_C = ./client.c
INCLUDE = ./minitalk.h

OBJ_SERVER = $(FILES_S:.c=.o)
OBJ_CLIENT = $(FILES_C:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -I $(INCLUDE) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -I $(INCLUDE) -o $(SERVER)

bonus: all

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:	clean
	$(RM) server client

re: fclean all
