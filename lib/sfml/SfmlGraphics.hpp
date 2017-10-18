//
// SfmlGraphics.hpp for sfml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/libs/sfml
//
// Made by dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  Mon Mar 27 14:13:39 2017 dourches
// Last update Sun Apr  9 10:26:08 2017 dourches
//

#ifndef		SFMLGRAPHICS_HPP_
# define	SFMLGRAPHICS_HPP_

# include	<SFML/Window.hpp>
# include	<SFML/Graphics.hpp>
# include	<SFML/System.hpp>
# include	<iostream>

# include	"IGraphics.hpp"

class SfmlContext;

class	SfmlGraph : public arcade::api::IGraphic
{
  SfmlContext &_context;
  std::map<arcade::TextureID, sf::Texture *> _texture;

public:
  SfmlGraph(SfmlContext &);
  ~SfmlGraph();

  void drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to, arcade::utl::Color const &color);
  void drawRectangle(arcade::utl::Position const &from, size_t width, size_t height, bool fill, arcade::utl::Color const &color);
  void drawCircle(arcade::utl::Position const &pos, size_t radius, arcade::utl::Color const &color);
  void drawSprite(arcade::utl::Position const &pos, arcade::TextureID texture_id, arcade::utl::Color const &color);
  void drawText(arcade::utl::Position const &pos, std::string const &text, arcade::utl::Color const &color);
  arcade::utl::Dimensions const &getDimensions() const;
  int loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Position const &pos, arcade::utl::Dimensions const &dimensions);
  void unloadSprites();
};

#endif		//SFMLGRAPHICS_HPP_
