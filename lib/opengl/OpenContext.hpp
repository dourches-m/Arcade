//
// OpenContext.hpp for Openn in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/opengl
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 09:52:48 2017 dourches
// Last update Sat Apr  8 23:39:59 2017 dourches
//

#ifndef		OPENCONTEXT_HPP_
# define	OPENCONTEXT_HPP_

# include	<iostream>
# include	"IContext.hpp"
# include	"IEvents.hpp"
# include	"OpenGraphics.hpp"
# include	"OpenEvent.hpp"

class OpenContext : public arcade::api::IContext
{
protected:
  sf::RenderWindow _window;
  std::string _name;
  OpenGraph _graph;
  OpenEvent _event;

public:
  OpenContext();
  ~OpenContext();

  arcade::api::IGraphic	&getGraphic();

  void		init();

  void		stop();

  void		clear();

  void		display();

  std::string const &getName() const;

  arcade::api::IEvents &getEvents();

  sf::RenderWindow *getWindow();
};

#endif		//OPENCONTEXT_HPP_
