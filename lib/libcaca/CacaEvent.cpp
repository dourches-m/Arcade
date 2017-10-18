//
// CacaEvent.cpp for Caca in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 17:50:02 2017 dourches
// Last update Sun Apr  9 05:49:23 2017 dourches
//

#include	"CacaContext.hpp"
#include	"CacaEvent.hpp"

CacaEvent::CacaEvent(CacaContext &context) : _context(context)
{
}

CacaEvent::~CacaEvent()
{
}

void	CacaEvent::pollEvents()
{
  int	keypress;
  caca_event_t	_event;

  while (!_key.empty())
    _key.pop_back();
  if (caca_get_event(_context.getDisplay(), CACA_EVENT_KEY_PRESS, &_event, 2) == 1)
    {
      keypress = _event.data.key.ch;
      if (keypress == 273)
	_key.push_back(IEvents::Key::UP);
      if (keypress == 274)
	_key.push_back(IEvents::Key::DOWN);
      if (keypress == 275)
	_key.push_back(IEvents::Key::LEFT);
      if (keypress == 276)
	_key.push_back(IEvents::Key::RIGHT);
      if (keypress == 27)
	_key.push_back(IEvents::Key::ESCAPE);
      if (keypress == 32)
	_key.push_back(IEvents::Key::SPACE);
      if (keypress == 49)
	_key.push_back(IEvents::Key::KEY_1);
      if (keypress == 50 || keypress == 233)
	_key.push_back(IEvents::Key::KEY_2);
      if (keypress == 51 || keypress == 34)
	_key.push_back(IEvents::Key::KEY_3);
      if (keypress == 52 || keypress == 39)
	_key.push_back(IEvents::Key::KEY_4);
      if (keypress == 53 || keypress == 40)
	_key.push_back(IEvents::Key::KEY_5);
      if (keypress == 54)
	_key.push_back(IEvents::Key::KEY_6);
      if (keypress == 55)
	_key.push_back(IEvents::Key::KEY_7);
      if (keypress == 56 || keypress == 95)
	_key.push_back(IEvents::Key::KEY_8);
      if (keypress == 57 || keypress == 231)
	_key.push_back(IEvents::Key::KEY_9);
      if (keypress == 13)
	_key.push_back(IEvents::Key::ENTER);
    }
}

bool	CacaEvent::keyPressed(IEvents::Key id) const
{
  for (auto it :_key)
    if (it == id)
      return (true);
  return (false);
}

std::vector<arcade::api::IEvents::Key> const &CacaEvent::getKey() const
{
  return (_key);
}

bool CacaEvent::mouseButtonPressed(arcade::api::IEvents::MouseKey id) const
{
  caca_event_t	_event;

  (void)id;
  if (caca_get_event(_context.getDisplay(), CACA_EVENT_MOUSE_PRESS, &_event, 2) == 1)
    return (true);
  return (false);
}

arcade::utl::Position CacaEvent::getMousePos() const
{
  return (arcade::utl::Position(caca_get_mouse_x(_context.getDisplay()), caca_get_mouse_y(_context.getDisplay())));
}
