//
// CacaEvent.hpp for CacaEvent in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/libcaca
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 16:37:54 2017 dourches
// Last update Thu Apr  6 09:55:44 2017 dourches
//

#ifndef		CACAEVENT_HPP_
# define	CACAEVENT_HPP_

# include	<vector>
# include	"IEvents.hpp"

class CacaContext;

class CacaEvent : public arcade::api::IEvents
{
  CacaContext &_context;
  std::vector<arcade::api::IEvents::Key> _key;

public:
  CacaEvent(CacaContext &);
  ~CacaEvent();

  void pollEvents();
  bool keyPressed(arcade::api::IEvents::Key id) const;
  bool mouseButtonPressed(arcade::api::IEvents::MouseKey id) const;
  arcade::utl::Position getMousePos() const;
  std::vector<arcade::api::IEvents::Key> const &getKey() const;
};


#endif		// CACAEVENT_HPP_
