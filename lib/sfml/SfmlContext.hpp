//
// SfmlContext.hpp for sfml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/libs/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Thu Mar 30 12:59:53 2017 dourches
// Last update Wed Apr  5 11:19:02 2017 dourches
//

#ifndef		SFMLCONTEXT_HPP_
# define	SFMLCONTEXT_HPP_

# include	"IContext.hpp"
# include	"IEvents.hpp"
# include	"SfmlGraphics.hpp"
# include	"SfmlEvent.hpp"

class SfmlContext : public arcade::api::IContext
{
protected:
  sf::RenderWindow _window;
  sf::Font _font;
  std::string _name;
  SfmlGraph _graph;
  SfmlEvent _event;

public:
  SfmlContext();
  ~SfmlContext();

  arcade::api::IGraphic	&getGraphic();

  void		init();

  void		stop();

  void		clear();

  void		display();

  std::string const &getName() const;

  arcade::api::IEvents &getEvents();

  sf::RenderWindow *getWindow();

  sf::Font const &getFont() const;
};

#endif		//SFMLCONTEXT_HPP_
