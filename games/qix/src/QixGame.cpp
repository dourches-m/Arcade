//
// QixGame.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 13:13:20 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//

#include <fstream>
#include "QixGame.hpp"

arcade::QixGame::QixGame() : _name("Qix"), _game_over(false), _score(0)
{
}

arcade::QixGame::~QixGame()
{

}

int	arcade::QixGame::init(api::IGraphic *graphics)
{
  graphic = graphics;
  //_map = QixMap();
  //_enemy = QixEnemy();
  //_player = QixPlayer();
//  _sparks.init();
  //_map.init(graphics);
  //  _sparks = init_sparks(_map);

//  _player.init();
  return 0;
}



int	arcade::QixGame::play(api::IEvents const &events)
{
  (void)events;
  return 0;
}

int	arcade::QixGame::close()
{
  return 0;
}

int	arcade::QixGame::restart()
{
  std::cerr << "Restarting Qix" << std::endl;
  return 0;
}

int	arcade::QixGame::getScore() const
{
  return 0;
}

void		arcade::QixGame::setPlayerName(std::string const &name)
{
  _player_name = name;
}

std::string const	&arcade::QixGame::getPlayerName() const
{
  return _player_name;
}

struct arcade::WhereAmI			*arcade::QixGame::where_am_i() const
{
  return NULL;
}

struct arcade::GetMap			*arcade::QixGame::get_map() const
{
  return NULL;
}

void *arcade::QixGame::play(arcade::CommandType event)
{
  switch (event)
    {
      case (arcade::CommandType::ILLEGAL):
	break;
      case(arcade::CommandType::GO_FORWARD):
	break;
      case(arcade::CommandType::SHOOT):
	break;
      case(arcade::CommandType::PLAY):
	{
	  //this->play();
	  break;
	}
      case(arcade::CommandType::GO_UP):
	{
	  _player.go_up(_map);
	  break;
	}
      case(arcade::CommandType::GO_DOWN):
	{
	  _player.go_down(_map);
	  break;
	}
      case(arcade::CommandType::GO_LEFT):
	{
	  _player.go_left(_map);
	  break;
	}
      case(arcade::CommandType::GO_RIGHT):
	{
	  _player.go_right(_map);
	  break;
	}
      case (arcade::CommandType::WHERE_AM_I):
	return this->where_am_i();
      case (arcade::CommandType::GET_MAP):
	return this->get_map();
      default:
	break;
    }
  return NULL;
}

extern "C" void Play()
{
  uint16_t user_command = 0;
  arcade::QixGame qix;

  qix.init(NULL);
  while (std::cin.read(reinterpret_cast<char *>(&user_command), sizeof(uint16_t)))
    qix.play(static_cast<arcade::CommandType>(user_command));
}

extern "C" arcade::api::AGame *entry_point()
{
  return new arcade::QixGame();
}

extern "C" void delete_point(arcade::api::AGame *entry)
{
  delete entry;
}
