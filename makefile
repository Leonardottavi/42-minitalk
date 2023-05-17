# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:24:28 by lottavi           #+#    #+#              #
#    Updated: 2023/05/17 14:29:24 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# toolchain stuff
CC = gcc

# flags
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS =
OPTI_FLAGS = -O3 -march=native

# artifacts
CLIENT = client
SERVER = server

# source files
COMMON_SRCS := printf
SERVER_SRCS := server.c
CLIENT_SRCS := client.c

# object files
COMMON_OBJS := ${addprefix obj/,${COMMON_SRCS:.c=.o}}
SERVER_OBJS := ${addprefix obj/,${SERVER_SRCS:.c=.o}}
CLIENT_OBJS := ${addprefix obj/,${CLIENT_SRCS:.c=.o}}

# include folders
INCLUDE = ${addprefix -I,include}

# lib folders
LIBD = ${addprefix -L,}

# libraries
LINK = ${addprefix -l,}

# thanks GNU Make
COMMON_SRCS := ${addprefix src/,${COMMON_SRCS}}
SERVER_SRCS := ${addprefix src/,${SERVER_SRCS}}
CLIENT_SRCS := ${addprefix src/,${CLIENT_SRCS}}

# why is this even mandatory
NAME = ${CLIENT}

# rules
all: ${CLIENT} ${SERVER}

${CLIENT}: ${COMMON_OBJS} ${CLIENT_OBJS}
	${CC} ${COMMON_OBJS} ${CLIENT_OBJS} ${LIBD} ${LINK} -o $@

${SERVER}: ${COMMON_OBJS} ${SERVER_OBJS}
	${CC} ${COMMON_OBJS} ${SERVER_OBJS} -o $@

obj/%.o: src/%.c obj
	${CC} ${CFLAGS} ${DEBUG_FLAGS} ${OPTI_FLAGS} ${INCLUDE} -c $< -o $@

obj:
	mkdir -p $@

clean:
	rm -rf obj

fclean: clean
	${RM} ${CLIENT} ${SERVER}

re:
	${MAKE} fclean
	${MAKE} all

norme:
	norminette include src

.PHONY: all clean fclean re norme
