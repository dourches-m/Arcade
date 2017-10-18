//
// OpenGraphics.hpp for Open in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/opengl
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 10:05:39 2017 dourches
// Last update Sun Apr  9 22:48:03 2017 maes_p
//

#ifndef		OPENGRAPHICS_HPP_
# define	OPENGRAPHICS_HPP_

# include	<SFML/OpenGL.hpp>
# include	<SFML/Window.hpp>
# include	<SFML/Graphics.hpp>
# include	<SFML/System.hpp>
# include	<GL/glu.h>
# include	"GL/glut.h"
# include	<GL/freeglut.h>
# include	"IGraphics.hpp"

class OpenContext;

class OpenGraph : public arcade::api::IGraphic
{
  OpenContext	&_context;
  std::map<arcade::TextureID, sf::Texture *> _texture;

public:
  OpenGraph(OpenContext &);
  ~OpenGraph();

  void drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to, arcade::utl::Color const &color);
  void drawRectangle(arcade::utl::Position const &from, size_t width, size_t height, bool fill, arcade::utl::Color const &color);
  void drawCircle(arcade::utl::Position const &pos, size_t radius, arcade::utl::Color const &color);
  int loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Dimensions const &dimensions);
  void unloadSprites();
  int loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Position const &pos, arcade::utl::Dimensions const &dimensions);
  void drawSprite(arcade::utl::Position const &pos, arcade::TextureID texture_id, arcade::utl::Color const &color);
  void drawText(arcade::utl::Position const &pos, std::string const &text, arcade::utl::Color const &color);
  arcade::utl::Dimensions const &getDimensions() const;
};

#endif		//OPENGRAPHICS_HPP_
