# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 12:59:37 by chorse            #+#    #+#              #
#    Updated: 2022/02/12 16:52:33 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = split.c main.c ft_sort_three.c ft_check.c ft_begin.c ft_atoi.c others.c ft_atoi.c ft_radix.c ft_lstsize.c ft_sort_five.c functions.c 

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o: $(HEADER)
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: ${NAME} 

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all