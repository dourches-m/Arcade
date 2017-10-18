//
// Menu.cpp for Menu in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/games/menu
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Apr  8 15:42:09 2017 dourches
// Last update Sun Apr  9 15:24:28 2017 dourches
//

#include	"Menu.hpp"

arcade::Menu::Menu() : lr(false)
{
}

arcade::Menu::~Menu()
{
}

int	arcade::Menu::play(arcade::api::IEvents const &event)
{
  if (event.keyPressed(arcade::api::IEvents::Key::LEFT))
    lr = false;
  else if (event.keyPressed(arcade::api::IEvents::Key::RIGHT))
    lr = true;
  if (event.keyPressed(arcade::api::IEvents::Key::ENTER))
    {
      if (lr == true)
	std::cout << "quix" << std::endl; //load_lib_snake
      else
	std::cout << "snake" << std::endl; //load_lib_snake
    }
  drawMenu();
  return (0);
}

int	arcade::Menu::init(arcade::api::IGraphic *fakegraphic)
{
  graphic = fakegraphic;
  return (0);
}

int	arcade::Menu::getScore() const
{
  return (0);
}

int	arcade::Menu::restart()
{
  return (0);
}

int	arcade::Menu::close()
{
  return (0);
}

void	arcade::Menu::setPlayerName(std::string const &name)
{
  _player_name = name;
}

std::string const &arcade::Menu::getPlayerName() const
{
  return (_player_name);
}

void	arcade::Menu::drawMenu() const
{
  graphic->drawRectangle(arcade::utl::Position(0, 0), 800, 800, true, arcade::utl::Color(0, 51, 255, 255));
  graphic->drawRectangle(arcade::utl::Position(0, 0), 800, 100, true, arcade::utl::Color(204, 204, 204, 255));  graphic->drawText(arcade::utl::Position(400, 50), "Menu", arcade::utl::Color(204, 204, 204, 255));
  graphic->drawRectangle(arcade::utl::Position(0, 100), 425, 700, true, arcade::utl::Color(102, 51, 102, 255));
  if (lr == false)
    {
      graphic->drawRectangle(arcade::utl::Position(100, 125), 180, 40, true, arcade::utl::Color(255, 255, 255,255));
      graphic->drawText(arcade::utl::Position(160, 150), "Snake",
			arcade::utl::Color(255, 255, 255, 255));
      graphic->drawText(arcade::utl::Position(600, 150), "Qix", arcade::utl::Color(0, 51, 255, 255));
    }
  else if (lr == true)
    {
      graphic->drawRectangle(arcade::utl::Position(525, 125), 180, 40, true, arcade::utl::Color(255, 255, 255,255));
      graphic->drawText(arcade::utl::Position(160, 150), "Snake",
			arcade::utl::Color(102, 51, 102, 255));
      graphic->drawText(arcade::utl::Position(600, 150), "Qix",
			arcade::utl::Color(255, 255, 255, 255));
    }
  graphic->drawText(arcade::utl::Position(530, 200), "Qix High Score", arcade::utl::Color(0, 51, 255, 255));
  graphic->drawText(arcade::utl::Position(100, 200), "Snake High Score",  arcade::utl::Color(102, 51, 102, 255));
}

extern "C" arcade::api::AGame *entry_point()
{
  return new arcade::Menu();
}

extern "C" void delete_point(arcade::api::AGame *entry)
{
  delete entry;
}

