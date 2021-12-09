# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 22:03:57 by nle-bret          #+#    #+#              #
#    Updated: 2021/12/09 11:46:04 by nle-bret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

DEBUG	?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
endif

ifeq ($(BEBUG), 2)
	CFLAGS += -D BUFFER_SIZE=xx
endif

NAME	= get_next_line.a

SRC_DIR	= ./

SRC		= get_next_line.c\
		  get_next_line_utils.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}

# BONUS	= 

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${BONUS:.c=.o}

CC		= gcc

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

#bonus:    ${OBJS} ${B_OBJS}
#	ar rc ${NAME} ${OBJS} ${B_OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
