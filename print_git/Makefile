# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 16:42:30 by chorse            #+#    #+#              #
#    Updated: 2021/12/14 16:42:31 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRCFILES=	ft_putnbr_fd.c			\
			ft_putstr_fd.c			\
			ft_putchar_fd.c			\
			ft_itoa.c		        \
			ft_conv.c		        \
			ft_strchr.c		        \
			ft_strlen.c             \
			ft_printf.c

HEADFILES=	ft_printf.h

OBJFILES= ${SRCFILES:.c=.o}

CC= gcc

%.o:	%.c ${HEADFILES}
		${CC} -Wall -Wextra -Werror -c $< -o $@

${NAME}:	${OBJFILES}
		${AR} rcs $@ ${OBJFILES}

all: ${NAME}

clean: 
	${RM} ${OBJFILES}

fclean: clean
	${RM} ${NAME}

re: fclean all
        
.PHONY: all clean fclean re 