//
// CacaContext.hpp for caca in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Thu Mar 30 13:50:27 2017 dourches
// Last update Sun Apr  9 22:39:34 2017 maes_p
//

#ifndef		CACACONTEXT_HPP_
# define	CACACONTEXT_HPP_

# include	"caca.h"
# include	<iostream>
# include	"IContext.hpp"
# include	"IEvents.hpp"
# include	"CacaGraphics.hpp"
# include	"CacaEvent.hpp"

class CacaContext : public arcade::api::IContext
{
  caca_canvas_t *_canvas;
  caca_display_t *_display;
  std::string _name;
  CacaGraph _graph;
  CacaEvent _event;

 public:
  CacaContext();

  ~CacaContext();

  arcade::api::IGraphic &getGraphic();

  void init();

  void stop();

  void clear();

  void display();

  arcade::api::IEvents &getEvents();

  std::string const &getName() const;

  caca_canvas_t *getCanvas();

  caca_display_t *getDisplay();
};


#endif		//CACACONTEXT_HPP_

