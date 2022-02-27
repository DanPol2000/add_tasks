# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:49:32 by chorse            #+#    #+#              #
#    Updated: 2022/02/27 15:59:11 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42 

SRC  =  main.c menu.c ft_split.c ft_atoi.c bresenham.c read_file.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o : %.c 
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) 

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : all clean fclean re
