//
// SfmlContext.cpp for Sfml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/libs/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Thu Mar 30 12:59:45 2017 dourches
// Last update Sun Apr  9 05:09:45 2017 dourches
//

#include	"SfmlContext.hpp"

SfmlContext::SfmlContext() : _name("Sfml"), _graph(SfmlGraph(*this)), _event(SfmlEvent(*this))
{
}

SfmlContext::~SfmlContext()
{
}

void	SfmlContext::init()
{
  sf::Font font;

  _window.create(sf::VideoMode(800, 600), "Arcade");
  if (!font.loadFromFile("arial.ttf"))
    {
      std::cerr << "This font is not available" << std::endl;
    }
  _font = font;
  clear();
}


arcade::api::IGraphic	&SfmlContext::getGraphic()
{
  return (_graph);
}

void		SfmlContext::stop()
{
  std::cerr << "Closing sfml's context" << std::endl;
  _window.close();
}

void		SfmlContext::clear()
{
  _window.clear(sf::Color::Black);
}

void		SfmlContext::display()
{
  _window.display();
}

std::string const	&SfmlContext::getName() const
{
  return (_name);
}

sf::RenderWindow	*SfmlContext::getWindow()
{
  return (&_window);
}

sf::Font		const	&SfmlContext::getFont() const
{
  return (_font);
}

arcade::api::IEvents			&SfmlContext::getEvents()
{
  return (_event);
}


extern "C" arcade::api::IContext *entry_point()
{
  return new SfmlContext();
}

extern "C" void delete_point(arcade::api::IContext *mod)
{
  delete mod;
}
