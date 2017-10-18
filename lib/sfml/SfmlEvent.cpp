//
// SfmlEvent.cpp for Sfml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Wed Apr  5 10:53:29 2017 dourches
// Last update Sun Apr  9 05:53:02 2017 dourches
//

#include	"SfmlContext.hpp"
#include	"SfmlEvent.hpp"

SfmlEvent::SfmlEvent(SfmlContext &context) : _context(context), _key()
{
}

SfmlEvent::~SfmlEvent()
{
}

void SfmlEvent::pollEvents()
{
  while (!_key.empty())
    _key.pop_back();
  while (_context.getWindow()->pollEvent(_event))
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	_key.push_back(IEvents::Key::LEFT);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	_key.push_back(IEvents::Key::RIGHT);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	_key.push_back(IEvents::Key::UP);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	_key.push_back(IEvents::Key::DOWN);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	_key.push_back(IEvents::Key::SPACE);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	_key.push_back(IEvents::Key::ESCAPE);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	_key.push_back(IEvents::Key::KEY_1);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	_key.push_back(IEvents::Key::KEY_2);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	_key.push_back(IEvents::Key::KEY_3);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	_key.push_back(IEvents::Key::KEY_4);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	_key.push_back(IEvents::Key::KEY_5);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	_key.push_back(IEvents::Key::KEY_6);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	_key.push_back(IEvents::Key::KEY_7);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	_key.push_back(IEvents::Key::KEY_8);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	_key.push_back(IEvents::Key::KEY_9);
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	_key.push_back(IEvents::Key::ENTER);
      else
	_key.push_back(IEvents::Key::UNKNOWN);
    }
}

  bool SfmlEvent::keyPressed(IEvents::Key id) const
  {
    for (auto it : _key)
      if (it == id)
	return (true);
    return (false);
  }

  std::vector<arcade::api::IEvents::Key> const &SfmlEvent::getKey() const
  {
    return (_key);
  }

  bool SfmlEvent::mouseButtonPressed(arcade::api::IEvents::MouseKey id) const
  {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && id == IEvents::MouseKey::M_BUTTON_1)
      return true;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && id == IEvents::MouseKey::M_BUTTON_2)
      return true;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && id == IEvents::MouseKey::M_BUTTON_3)
      return true;
    else
      return (false);
  }

  arcade::utl::Position SfmlEvent::getMousePos() const
  {
    sf::Vector2i localPosition = sf::Mouse::getPosition(*(_context.getWindow()));
    return(arcade::utl::Position(localPosition.x,localPosition.y));
  }
