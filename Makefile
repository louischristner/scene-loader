CC		=	g++

SRC		=	main.cpp	\
			Person.cpp	\
			Scene.cpp	\
			Game.cpp

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
