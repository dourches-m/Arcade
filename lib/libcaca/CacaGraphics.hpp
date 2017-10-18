//
// CacaGraph.hpp for Caca in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/libcaca
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Mar 29 18:24:22 2017 dourches
// Last update Sun Apr  9 17:51:47 2017 dourches
//

#ifndef		CACAGRAPHICS_HPP_
# define	CACAGRAPHICS_HPP_

# include	<iostream>
# include	<map>
# include	"CacaContext.hpp"

class CacaContext;

class CacaGraph : public arcade::api::IGraphic
{
  CacaContext &_context;
  std::map<arcade::TextureID, std::string> _texture;

public:
  CacaGraph(CacaContext &);
  ~CacaGraph();

  void drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to, arcade::utl::Color const &color);
  void drawRectangle(arcade::utl::Position const &from, size_t width, size_t height, bool fill,
		     arcade::utl::Color const &color);
  void drawCircle(arcade::utl::Position const &pos, size_t radius, arcade::utl::Color const &color);
  int loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Dimensions const &dimensions);
  void unloadSprites();
  int loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Position const &pos, arcade::utl::Dimensions const &dimensions);
  void drawSprite(arcade::utl::Position const &pos, arcade::TextureID texture_id, arcade::utl::Color const &color);
  void drawText(arcade::utl::Position const &pos, std::string const &text, arcade::utl::Color const &color);
  arcade::utl::Dimensions const &getDimensions() const;
};

#endif		//CACAGRAPHICS_HPP_
