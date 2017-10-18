##
## Makefile for Makefile in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/libs
## 
## Made by dourches
## Login   <martin.dourches@epitech.eu>
## 
## Started on  Mon Mar 27 13:42:26 2017 dourches
## Last update Sun Apr  9 22:51:43 2017 maes_p
##

NAME1	=	lib_arcade_sfml.so

NAME2	=	lib_arcade_caca.so

NAME3	=	lib_arcade_opengl.so

SRC1	=	sfml/SfmlGraphics.cpp		\
		sfml/SfmlContext.cpp		\
		sfml/SfmlEvent.cpp

SRC2	=	libcaca/CacaGraphics.cpp	\
		libcaca/CacaContext.cpp		\
		libcaca/CacaEvent.cpp

SRC3	=	opengl/OpenGraphics.cpp 	\
		opengl/OpenContext.cpp		\
		opengl/OpenEvent.cpp

OBJ1	=	$(SRC1:.cpp=.o)

OBJ2	=	$(SRC2:.cpp=.o)

OBJ3	=	$(SRC3:.cpp=.o)

CXXFLAGS+=	-Wall -Wextra -fPIC -I../includes/Wrappers/ -I../includes/utils/ -I../sfml/ -std=c++11 -I../includes/libadd/caca -L../includes/libadd/caca -I../includes/libadd/GL -I../includes/libadd/OpenGL -I../includes/libadd/ELG -I../includes/libadd/GLES -I../includes/libadd/GLES2 -I../includes/libadd/

all	:	$(NAME1) $(NAME2) $(NAME3)

$(NAME1) :	$(OBJ1)
		g++ -shared -o $(NAME1) $(OBJ1) $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME2) :	$(OBJ2)
		g++ -shared -o $(NAME2) $(OBJ2) $(CXXFLAGS) -L../includes/libadd/caca -lcaca 

$(NAME3) :	$(OBJ3)
		g++ -shared -o $(NAME3) $(OBJ3) $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU -lglut -L../includes/libadd/OpenGL

clean	:
		rm -rf $(OBJ1)
		rm -rf $(OBJ2)
		rm -rf $(OBJ3)

fclean	:	clean
		rm -rf $(NAME1)
		rm -rf $(NAME2)
		rm -rf $(NAME3)

re	:	fclean all
