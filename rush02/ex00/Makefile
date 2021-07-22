# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 11:28:29 by marnaudy          #+#    #+#              #
#    Updated: 2021/07/18 11:30:04 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02

SRCS	= main.c ft_translate.c ft_read_file.c ft_file_basic.c ft_split.c ft_split_basic.c ft_display.c ft_display_basic.c ft_helper.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
