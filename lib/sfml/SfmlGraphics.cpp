//
// SfmlGraphics.cpp for sfml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/libs
//
// Made by dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  Mon Mar 27 13:48:31 2017 dourches
// Last update Sun Apr  9 18:29:15 2017 dourches
//

#include	"SfmlContext.hpp"
#include	"SfmlGraphics.hpp"

SfmlGraph::SfmlGraph(SfmlContext &context) : _context(context)
{
}

SfmlGraph::~SfmlGraph()
{
}

void SfmlGraph::drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to, arcade::utl::Color const &color)
{
  sf::Color Color(color._color.r, color._color.g, color._color.b, color._color.a);
  sf::Vertex line[] =
    {
      sf::Vertex(sf::Vector2f(from.x, from.y)),
      sf::Vertex(sf::Vector2f(to.x, to.y))
    };
  line[0].color = Color;
  line[1].color = Color;
  _context.getWindow()->draw(line, 2, sf::Lines);
}

void SfmlGraph::drawRectangle(arcade::utl::Position const &from, size_t width, size_t height, bool fill,
			      arcade::utl::Color const &color)
{
  sf::RectangleShape rectangle(sf::Vector2f(width, height));
  sf::Color Color(color._color.r, color._color.g, color._color.b, color._color.a);

  if (fill == true)
    {
      rectangle.move(from.x, from.y);
      rectangle.setFillColor(Color);
      _context.getWindow()->draw(rectangle);
    }
  else
    {
      drawLine(arcade::utl::Position(from.x, from.x), arcade::utl::Position(from.y + height, from.y), color);
      drawLine(arcade::utl::Position(from.x, from.x + width),
	       arcade::utl::Position(from.y, from.y), color);
      drawLine(arcade::utl::Position(from.x, from.x + width),
	       arcade::utl::Position(from.y + height, from.y + height), color);
      drawLine(arcade::utl::Position(from.x + width, from.x + width),
	       arcade::utl::Position(from.y + height, from.y), color);
    }
}

void SfmlGraph::drawCircle(arcade::utl::Position const &pos, size_t radius, arcade::utl::Color const &color)
{
  sf::CircleShape circle(radius);
  sf::Color Color(color._color.r, color._color.g, color._color.b, color._color.a);
  circle.setPosition(pos.x - radius, pos.y - radius);
  circle.setFillColor(Color);
  _context.getWindow()->draw(circle);
}

void	SfmlGraph::unloadSprites()
{
  if ( !_texture.empty())
    _texture.clear();
}

int	SfmlGraph::loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Position const &pos, arcade::utl::Dimensions const &dimensions)
{
  sf::Texture *tex = new sf::Texture();

  (void)pos;
  (void)dimensions;
  if (!tex->loadFromFile(file))
    {
      std::cerr << "Can't load texture" << std::endl;
      return (1);
    }
  _texture[id] = tex;
  return (0);
}

void SfmlGraph::drawSprite(arcade::utl::Position const &pos, arcade::TextureID texture_id,
			   arcade::utl::Color const &color)
{
  sf::Sprite sprite;
  sf::Vector2u tmp;

  (void)color;
  if ( !_texture.empty())
    {
      sprite.setTexture(*(_texture[texture_id]));
      tmp = _texture[texture_id]->getSize();
      sprite.move(static_cast<double>(pos.x) * 800, static_cast<double>(pos.y) * 600 + 100);
      _context.getWindow()->draw(sprite);
    }
}

void SfmlGraph::drawText(arcade::utl::Position const &pos, std::string const &text,
			 arcade::utl::Color const &color)
{
  sf::Text Text;
  sf::Color Color(color._color.r, color._color.g, color._color.b, color._color.a);
  Text.setFont(_context.getFont());
  Text.setString(text);
  Text.setColor(sf::Color::Black);
  Text.setPosition(pos.x, pos.y - 20);
  _context.getWindow()->draw(Text);
}

arcade::utl::Dimensions const &SfmlGraph::getDimensions() const
{
  arcade::utl::Dimensions *dim= new arcade::utl::Dimensions(800, 600);

  return (*dim);
}
