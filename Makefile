CC		=	g++

SRC		=	main.cpp	\
			sources/Person.cpp	\
			sources/Scene.cpp	\
			sources/Game.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	scene-loader

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
