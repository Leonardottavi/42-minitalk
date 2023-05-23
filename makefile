# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:46:32 by lottavi           #+#    #+#              #
#    Updated: 2023/05/23 10:48:13 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: client server

client: client.c libft/libft.a
	$(CC) $(CFLAGS) -I./inc client.c -L./libft -lft -o client

server: server.c libft/libft.a
	$(CC) $(CFLAGS) -I./inc server.c -L./libft -lft -o server

libft/libft.a:
	make -C libft

clean:
	rm -f client server *.o

fclean: clean
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
