# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:46:32 by lottavi           #+#    #+#              #
#    Updated: 2023/05/26 16:04:27 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_PATH		=	./printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

SOURCES_FILESS	=	client.c
SOURCES_FILESC	=	server.c

OBJECTSS			= 	$(SOURCES_FILESS:.c=.o)
OBJECTSC			= 	$(SOURCES_FILESC:.c=.o)

NAMEC			=	client
NAMES			=	server

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

%.o:%.c
	$(CC) ${CFLAGS}  -c $< -o $@

all:			$(NAMEC) $(NAMES)

$(NAMEC):	$(OBJECTSS) $(PRINTF)
				$(CC) $(OBJECTSS) $(PRINTF) -o $(NAMEC)
$(NAMES):	$(OBJECTSC) $(PRINTF)
				$(CC) $(OBJECTSC) $(PRINTF) -o $(NAMES)

$(PRINTF):
				make -C $(PRINTF_PATH)

clean:
				${RM} ${OBJECTSS} ${OBJECTSC}
				make clean -C ${PRINTF_PATH}

fclean:			clean
					rm -f $(NAMEC) $(NAMES)
					rm -f $(PRINTF)

re:				fclean all

.PHONY:			all clean re
