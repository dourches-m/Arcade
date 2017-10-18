//
// CacaGraphics.cpp for Caca in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/libs/libcaca
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Mar 29 18:49:02 2017 dourches
// Last update Sun Apr  9 18:12:42 2017 dourches
//

#include	<cstdint>
#include	<fstream>
#include	<iostream>
#include	<string>
#include	<sstream>
#include	"CacaContext.hpp"
#include	"CacaGraphics.hpp"

uint16_t createARGB(int a, int r, int g, int b)
{
  r = r / 17;
  g = g / 17;
  b = b / 17;
  a = a / 17;
  return ((a & 0xf) << 12) + ((r & 0xf) << 8) + ((g & 0xf) << 4)
    + (b & 0xf);
}

CacaGraph::CacaGraph(CacaContext &context) : _context(context)
{
}

CacaGraph::~CacaGraph()
{
}

void CacaGraph::drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to,
			 arcade::utl::Color const &color)
{
  caca_set_color_argb(_context.getCanvas(), createARGB(color._color.a, color._color.r, color._color.g, color._color.b), createARGB(color._color.a, color._color.r, color._color.g, color._color.b));
  caca_draw_line(_context.getCanvas(), from.x / 10, from.y / 10, to.x / 10, to.y / 10, ' ');
}

void CacaGraph::drawRectangle(arcade::utl::Position const &from, size_t width,
			      size_t height, bool fill, arcade::utl::Color const &color)
{
  caca_set_color_argb(_context.getCanvas(), createARGB(color._color.a, color._color.r, color._color.g, color._color.b), createARGB(color._color.a, color._color.r, color._color.g, color._color.b));
  caca_draw_box(_context.getCanvas(), from.x / 10, from.y / 10, width / 10, height / 10, ' ');
  if (fill == true)
    caca_fill_box(_context.getCanvas(), from.x / 10, from.y / 10, width / 10, height / 10, ' ');
}

void CacaGraph::drawText(arcade::utl::Position const &pos,
			 std::string const &text, arcade::utl::Color const &color)
{
  caca_set_color_argb( _context.getCanvas(),0, createARGB(color._color.a, color._color.r, color._color.g, color._color.b));
  caca_put_str(_context.getCanvas(), pos.x / 10, pos.y / 10, text.c_str());
}

void CacaGraph::drawCircle(arcade::utl::Position const &pos,
			   size_t radius, arcade::utl::Color const &color)
{
  caca_set_color_argb(_context.getCanvas(), createARGB(color._color.a, color._color.r, color._color.g, color._color.b), createARGB(color._color.a, color._color.r, color._color.g, color._color.b));
  caca_draw_circle(_context.getCanvas(), pos.x  / 10, pos.y  / 10, radius / 10, ' ');
  caca_fill_ellipse(_context.getCanvas(), pos.x / 10, pos.y / 10, radius / 10, radius / 10, ' ');
  return;
}

void	CacaGraph::unloadSprites()
{
  _texture.clear();
}

int	CacaGraph::loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Position const &pos,arcade::utl::Dimensions const &dimensions)
{
  std::string name;
  std::ifstream ifs(file);
  std::ostringstream ss;

  (void)dimensions;
  (void)pos;
  if (ifs.is_open())
    {
      while (! ifs.eof())
	{
	  getline(ifs, name);
	  ss << name;
	  ss << '\n';
	}
      _texture[id] = ss.str();
      ifs.close();
    }
  else
    std::cerr << "No file found" << std::endl;
  return (0);
}

void CacaGraph::drawSprite(arcade::utl::Position const &pos,
			   arcade::TextureID texture_id, arcade::utl::Color const &color)
{
  drawText(pos, _texture[texture_id], color);
  return;
}

arcade::utl::Dimensions const &CacaGraph::getDimensions() const
{
  arcade::utl::Dimensions *dim = new arcade::utl::Dimensions(800, 600);

  return (*dim);
}
