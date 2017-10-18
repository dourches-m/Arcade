//
// OpenGraphics.cpp for Open in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/opengl
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 10:08:55 2017 dourches
// Last update Sun Apr  9 18:42:06 2017 dourches
//

#include	<math.h>
#include	"OpenContext.hpp"
#include	"OpenGraphics.hpp"

OpenGraph::OpenGraph(OpenContext &context) : _context(context)
{
}

OpenGraph::~OpenGraph()
{
}

void OpenGraph::drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to, arcade::utl::Color const &color)
{
  glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  glBegin(GL_LINES);
  glVertex2f(from.x, from.y);
  glVertex2f(to.x, to.y );
  glEnd();
  glColor4ub(0, 0, 0, 0);
}

void OpenGraph::drawRectangle(arcade::utl::Position const &from, size_t width, size_t height, bool fill,
			      arcade::utl::Color const &color)
{
  glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  if (fill == false)
    {
      glBegin(GL_QUADS);
      glVertex2f(from.x, from.y);
      glVertex2f(from.x + width, from.y);
      glVertex2f(from.x + width, from.y + height);
      glVertex2f(from.x, from.y + height);
      glEnd();
    }
  else
    glRectf(from.x, from.y, (from.x + width), (from.y + height));
  glColor4ub(0, 0, 0, 0);
}

void OpenGraph::drawCircle(arcade::utl::Position const &pos, size_t radius, arcade::utl::Color const &color)
{
  glBegin(GL_LINE_LOOP);
  glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  for (int ii = 0; ii < 100; ii++)   {
    float theta = 2.0f * 3.1415926f * float(ii) / float(100);
    float x = radius * cosf(theta);
    float y = radius * sinf(theta);
    glVertex2f(x + pos.x, y + pos.y);
  }
  glEnd();
  glColor4ub(0, 0, 0, 0);
}

int OpenGraph::loadSprite(arcade::TextureID id, std::string const &file, arcade::utl::Position const &pos, arcade::utl::Dimensions const &dimensions)
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

void OpenGraph::unloadSprites()
{
  if ( !_texture.empty())
    _texture.clear();
}

void OpenGraph::drawSprite(arcade::utl::Position const &pos, arcade::TextureID texture_id,
			   arcade::utl::Color const &color)
{
  sf::Sprite sprite;
  sf::Vector2u tmp;

  (void)color;
  _context.getWindow()->pushGLStates();
  if ( !_texture.empty())
    {
      sprite.setTexture(*(_texture[texture_id]));
      tmp = _texture[texture_id]->getSize();
      sprite.move(static_cast<double>(pos.x) * 800, static_cast<double>(pos.y) * 600 + 100);
      _context.getWindow()->draw(sprite);
    }
  _context.getWindow()->popGLStates();
}

void OpenGraph::drawText(arcade::utl::Position const &pos, std::string const &text,
			 arcade::utl::Color const &color)
{
  const unsigned char *utext = reinterpret_cast<const unsigned char *>(text.c_str());
  glRasterPos2i(pos.x, pos.y);
  (void)color;
  //    glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  glColor4ub(255, 255, 255, 255);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, utext);
  glColor4ub(0, 0, 0, 0);
}

arcade::utl::Dimensions const &OpenGraph::getDimensions() const
{
  arcade::utl::Dimensions *dim= new arcade::utl::Dimensions(800, 600);

  return (*dim);
}
