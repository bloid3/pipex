# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 11:34:03 by marvin            #+#    #+#              #
#    Updated: 2023/10/02 11:34:03 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pipex.c utils.c functions.c split.c

OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJBS} ${OBJS}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re