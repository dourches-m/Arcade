//
// SfmlEvent.hpp for SFml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 10:44:16 2017 dourches
// Last update Wed Apr  5 17:38:57 2017 dourches
//

#ifndef		SFMLEVENT_HPP_
# define	SFMLEVENT_HPP_

# include	"IEvents.hpp"

class SfmlContext;

class SfmlEvent : public arcade::api::IEvents
{
  SfmlContext &_context;
  sf::Event _event;
  std::vector<arcade::api::IEvents::Key> _key;

public:
  SfmlEvent(SfmlContext &);
  ~SfmlEvent();

  void	pollEvents();
  bool	keyPressed(arcade::api::IEvents::Key id) const;
  bool	mouseButtonPressed(arcade::api::IEvents::MouseKey id) const;
  arcade::utl::Position	getMousePos() const;
  std::vector<arcade::api::IEvents::Key> const &getKey() const;
};

#endif		//SFMLEVENT_HPP_
