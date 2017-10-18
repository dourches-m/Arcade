##
## Makefile for arcade in /home/hurlu/rendu/
##
## Made by Hugo Willaume
## Login   <hugo.willaume@epitech.eu>
##
## Started on  Wed Mar 22 13:16:23 2017 Hugo Willaume
## Last update Sat Apr  8 09:25:09 2017 dourches
##

NAME = arcade

SRC =	src/main.cpp		\
	src/Core.cpp		\
        src/core_loop.cpp	\

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -W -Wall -Wextra -Iincludes -Iincludes/Wrappers -Iincludes/utils -Iincludes/Core
ifeq ($(DEBUG), 1)
CXXFLAGS += -ggdb3
else
CXXFLAGS += -Werror
endif

LIBS = -ldl

CXX = g++ -std=c++11

all: $(NAME)
	make -C games
	make -C lib


$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)
	make -C lib clean
	make -C games clean


fclean: clean
	rm -f $(NAME)
	make -C lib fclean
	make -C games fclean

re: fclean all
