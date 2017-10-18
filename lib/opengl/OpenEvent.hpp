//
// SfmlEvent.hpp for SFml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 10:44:16 2017 dourches
// Last update Thu Apr  6 22:14:22 2017 dourches
//

#ifndef		OPENEVENT_HPP_
# define	OPENEVENT_HPP_

# include	"IEvents.hpp"

class OpenContext;

class OpenEvent : public arcade::api::IEvents
{
  OpenContext &_context;
  sf::Event _event;
  std::vector<arcade::api::IEvents::Key> _key;

public:
  OpenEvent(OpenContext &);
  ~OpenEvent();

  void	pollEvents();
  bool	keyPressed(arcade::api::IEvents::Key id) const;
  bool	mouseButtonPressed(arcade::api::IEvents::MouseKey id) const;
  arcade::utl::Position	getMousePos() const;
  std::vector<arcade::api::IEvents::Key> const &getKey() const;
};

#endif		//OPENEVENT_HPP_
