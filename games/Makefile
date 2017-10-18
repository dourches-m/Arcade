##
## Makefile for arcade_games in /home/hurlu/rendu/
##
## Made by Hugo Willaume
## Login   <hugo.willaume@epitech.eu>
##
## Started on  Tue Apr 4 11:55:23 2017 Hugo Willaume
## Last update Sun Apr  9 00:42:07 2017 dourches
##

NAME_QIX = libarcade_qix.so

NAME_SNAKE	=	libarcade_snake.so

NAME_MENU	=	libarcade_menu.so

SRC_QIX =	qix/src/QixEnemy.cpp	\
		qix/src/QixGame.cpp	\
		qix/src/QixMap.cpp	\
		qix/src/QixPlayer.cpp	\
		qix/src/QixSpark.cpp	\

SRC_SNAKE	=	snake/src/Snake.cpp \
			snake/src/Play.cpp \

SRC_MENU	=	menu/src/Menu.cpp \

OBJ_QIX =	$(SRC_QIX:.cpp=.o)

OBJ_SNAKE	 =	$(SRC_SNAKE:.cpp=.o)

OBJ_MENU	=	$(SRC_MENU:.cpp=.o)

CXX = g++ -fPIC

CXXFLAGS = -W -Wall -Wextra -Iqix/includes/ -Isnake/include/ -Imenu/include/ -I../includes/utils -I../includes/Wrappers -std=c++11

ifeq ($(DEBUG), 1)
CXXFLAGS += -ggdb3
else
CXXFLAGS += -Werror
endif

all : $(NAME_QIX) $(NAME_SNAKE) $(NAME_MENU)

snake:		$(NAME_SNAKE)

$(NAME_QIX): $(OBJ_QIX)
	g++ -o $(NAME_QIX) $(OBJ_QIX) -shared

$(NAME_SNAKE): $(OBJ_SNAKE)
	g++ -o $(NAME_SNAKE) $(OBJ_SNAKE) -shared

$(NAME_MENU): $(OBJ_MENU)
	g++ -o $(NAME_MENU) $(OBJ_MENU) -shared

clean :
	rm -f $(OBJ_QIX) $(OBJ_SNAKE) $(OBJ_MENU)

fclean : clean
	rm -f $(NAME_QIX) $(NAME_SNAKE) $(NAME_MENU)

re : fclean all
