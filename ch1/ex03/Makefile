NAME 	=	Unnecessary_violence
HDR		=	main.h Weapon.h HumanA.h HumanB.h
SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ		=	$(patsubst %.cpp,%.o,$(SRC))

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

%.o:		%.cpp $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
