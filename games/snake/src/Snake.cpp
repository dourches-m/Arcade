//
// Snake.cpp for arcade in /home/pauline/rendu/cpp/cpp_arcade/games/snake/src
// 
// Made by Pauline Maes
// Login   <maes_p@epitech.eu>
// 
// Started on  Tue Apr  4 16:43:56 2017 Pauline Maes
// Last update Sun Apr  9 22:32:17 2017 maes_p
//

#include		<iostream>
#include		<stdlib.h>
#include		<cstddef>
#include		<unistd.h>
#include		<stdint.h>
#include		<time.h>
#include		"Snake.hpp"

arcade::Snake::Snake()
  : _height(MAP_SIZE), _width(MAP_SIZE), _last_pos(HEAD_POS - 4, HEAD_POS), _food_pos(1, 1),
    _head_pos(HEAD_POS, HEAD_POS), _direction(0), _score(0), _player_name(""), _game_over(false)
{
  _snake_pos.emplace_back(HEAD_POS, HEAD_POS);
  _snake_pos.emplace_back(HEAD_POS - 1, HEAD_POS);
  _snake_pos.emplace_back(HEAD_POS - 2, HEAD_POS);
  _snake_pos.emplace_back(HEAD_POS - 3, HEAD_POS);
  this->setFoodPos();
}

arcade::Snake::~Snake()
{

}

int			arcade::Snake::init(api::IGraphic *graphics)
{
  srand(time(NULL));
  graphic = graphics;
  return (0);
}

int			arcade::Snake::close()
{
  _snake_pos.clear();
  return (0);
}

int			arcade::Snake::restart()
{
  
  _head_pos.x = HEAD_POS;
  _head_pos.y = HEAD_POS;
  _snake_pos.clear();
  _snake_pos.emplace_back(HEAD_POS, HEAD_POS);
  _snake_pos.emplace_back(HEAD_POS - 1, HEAD_POS);
  _snake_pos.emplace_back(HEAD_POS - 2, HEAD_POS);
  _snake_pos.emplace_back(HEAD_POS - 3, HEAD_POS);
  this->setFoodPos();
  this->setLastPos(HEAD_POS - 4, HEAD_POS);
  _direction = 0;
  _score = 0;
  _game_over = false;
  return (0);
}

int			arcade::Snake::getHeight() const
{
  return (_height);
}

int			arcade::Snake::getWidth() const
{
  return (_width);
}

const arcade::utl::Position & arcade::Snake::getLastPos() const
{
  return (_last_pos);
}

void			arcade::Snake::setLastPos(const int x, const int y)
{
  _last_pos.x = x;
  _last_pos.y = y;
}

const arcade::utl::Position & arcade::Snake::getFoodPos() const
{
  return (_food_pos);
}

void			arcade::Snake::setFoodPos()
{
  size_t				x;
  size_t				y;
  size_t				i;

  while (1)
    {
      i = 0;
      x = rand() % (MAP_SIZE - 2) + 1;
      y = rand() % (MAP_SIZE - 2) + 1;
      while (i < _snake_pos.size())
	{
	  if (_snake_pos[i].x != x && _snake_pos[i].y != y)
	    {
	      _food_pos.x = x;
	      _food_pos.y = y;
	      return ;
	    }
	  i++;
	}
    }
}

std::vector<arcade::utl::Position>	arcade::Snake::getSnakePos() const
{
  return (_snake_pos);
}

void			arcade::Snake::moveSnake()
{
  size_t		x;
  size_t		y;

  _last_pos.x = _snake_pos.back().x;
  _last_pos.y = _snake_pos.back().y;
  x = _snake_pos[0].x;
  y = _snake_pos[0].y;
  if (_direction == 0)
    x++;
  else if (_direction == 1)
    y++;
  else if (_direction == 2)
    x--;
  else
    y--;
  
  _head_pos.x = x;
  _head_pos.y = y;
  _snake_pos.insert(_snake_pos.begin(), utl::Position(x, y));
  _snake_pos.pop_back();
}

void			arcade::Snake::incrSnake()
{
  arcade::utl::Position	new_pos(_last_pos.x, _last_pos.y);

  _snake_pos.push_back(new_pos);
  incrScore();
}

int		        arcade::Snake::getScore() const
{
  return (_score);
}

void		        arcade::Snake::incrScore()
{
  _score += 100;
}

int			arcade::Snake::checkSnake()
{
  std::vector<int>::size_type		i;

  i = 1;
  if (_head_pos.x == 0 || _head_pos.x == MAP_SIZE - 1)
    {
      sleep(1);
      restart();
    }
  else if (_head_pos.y == 0 || _head_pos.y == MAP_SIZE - 1)
    {
      sleep(1);
      restart();
    }
  while (i < _snake_pos.size())
    {
      if (_head_pos.x == _snake_pos[i].x && _head_pos.y == _snake_pos[i].y)
	{
	  sleep(1);
	  restart();
	}
      i++;
    }
  if (_head_pos.x == _food_pos.x && _head_pos.y == _food_pos.y)
    {
      setFoodPos();
      incrSnake();
    }
  return (0);
}

void			arcade::Snake::play()
{
  moveSnake();
  if (checkSnake() == 1)
    {
      _game_over = true;
      restart();
    }
}

void			arcade::Snake::play(const CommandType event)
{
  switch (static_cast<uint16_t >(event))
    {
    case (static_cast<int>(arcade::CommandType::WHERE_AM_I)) :
      std::cerr << "whereAmI" << std::endl;
      whereAmI();
      break;
    case (static_cast<int>(arcade::CommandType::GET_MAP)) :
      std::cerr << "getMap" << std::endl;
      getMap();
      break;
    case (static_cast<int>(arcade::CommandType::ILLEGAL)) :
      break;
    case (static_cast<int>(arcade::CommandType::GO_FORWARD)) :
      break;
    case (static_cast<int>(arcade::CommandType::SHOOT)) :
      break;
    case (static_cast<int>(arcade::CommandType::GO_UP)) :
      std::cerr << "go up" << std::endl;
      goUp();
      break;
    case (static_cast<int>(arcade::CommandType::GO_DOWN)) :
      std::cerr << "go down" << std::endl;
      goDown();
      break;
    case (static_cast<int>(arcade::CommandType::GO_LEFT)) :
      std::cerr << "go left" << std::endl;
      goLeft();
      break;
    case (static_cast<int>(arcade::CommandType::GO_RIGHT)) :
      std::cerr << "go right" << std::endl;
      goRight();
      break;
    case (static_cast<int>(arcade::CommandType::PLAY)) :
      std::cerr << "play" << std::endl;
      play();
      break;
      default:
	std::cerr << "Unhandled command !" << std::endl;
    }
}

std::string const &	arcade::Snake::getPlayerName() const
{
  return (_player_name);
}

void			arcade::Snake::setPlayerName(std::string const &name)
{
  _player_name = name;
}

int			arcade::Snake::play(api::IEvents const &events)
{
  if (events.keyPressed(arcade::api::IEvents::Key::LEFT))
    goLeft();
  if (events.keyPressed(arcade::api::IEvents::Key::RIGHT))
    goRight();
  if (events.keyPressed(arcade::api::IEvents::Key::UP))
    goUp();
  if (events.keyPressed(arcade::api::IEvents::Key::DOWN))
    goDown();
  moveSnake();
  if (checkSnake() == 1)
    _game_over = true;
  DrawMap(*this);
  DrawSnake(*this);
  DrawFood(*this);
  return (0);
}

void			arcade::Snake::goUp()
{
  if (_direction != 1)
    _direction = 3;
}

void			arcade::Snake::goDown()
{
  if (_direction != 3)
    _direction = 1;
}

void			arcade::Snake::goLeft()
{
  if (_direction != 0)
    _direction = 2;
}

void			arcade::Snake::goRight()
{
  if (_direction != 2)
    _direction = 0;
}

void			arcade::Snake::getMap() const
{
  size_t		i;
  arcade::GetMap	*map = new arcade::GetMap[MAP_SIZE * MAP_SIZE * sizeof(arcade::TileType)];

  map->type = arcade::CommandType::GET_MAP;
  map->width = static_cast<uint16_t>(MAP_SIZE);
  map->height = static_cast<uint16_t>(MAP_SIZE);
  i = 0;
  while (i < MAP_SIZE * MAP_SIZE)
    {
      if (i % MAP_SIZE == 0 || i < MAP_SIZE || i > (MAP_SIZE * MAP_SIZE) - MAP_SIZE
	  || (i + 1) % MAP_SIZE == 0)
      	map->tile[i] = arcade::TileType::BLOCK;
      else
	map->tile[i] = arcade::TileType::EMPTY;
      i++;
    }
  map->tile[_food_pos.y * MAP_SIZE + _food_pos.x] = arcade::TileType::POWERUP;
  std::cout.write(reinterpret_cast<char *>(map), sizeof(arcade::GetMap) + (MAP_SIZE * MAP_SIZE * sizeof(arcade::TileType)));
}

void			arcade::Snake::whereAmI() const
{
  size_t 		i = 0;
  arcade::WhereAmI	*whereami = new WhereAmI[_snake_pos.size() * sizeof(arcade::Position) - 4];

  whereami->type = arcade::CommandType::WHERE_AM_I;
  whereami->lenght = static_cast<uint16_t>(_snake_pos.size());
  while (i < _snake_pos.size())
    {
      whereami->position[i].x = _snake_pos[i].x;
      whereami->position[i].y = _snake_pos[i].y;
      i++;
    }
  std::cout.write(reinterpret_cast<char *>(whereami), sizeof(whereami) + _snake_pos.size() * sizeof(arcade::Position) - 4);
}

void			arcade::Snake::DrawMap(const Snake &snake) const
{
  snake.graphic->drawRectangle(arcade::utl::Position(0, 0), TILE_SIZE * MAP_SIZE, TILE_SIZE * MAP_SIZE, true, arcade::utl::Color(169, 81, 14, 255));
  snake.graphic->drawRectangle(arcade::utl::Position(TILE_SIZE, TILE_SIZE), TILE_SIZE * (MAP_SIZE - 2), TILE_SIZE * (MAP_SIZE - 2), true, arcade::utl::Color(255, 178, 102, 255));
}

void			arcade::Snake::DrawSnake(const Snake &snake) const
{
  std::vector<int>::size_type i = 0;

  while (i < snake._snake_pos.size())
    {
      if (i == 0)
	{
	  snake.graphic->drawRectangle(arcade::utl::Position((snake._snake_pos[i].x * TILE_SIZE),
							      (snake._snake_pos[i].y * TILE_SIZE)),
					TILE_SIZE, TILE_SIZE, true, arcade::utl::Color(0, 153, 0, 255));
	}
      else
	{
	  snake.graphic->drawRectangle(arcade::utl::Position((snake._snake_pos[i].x * TILE_SIZE),
							      (snake._snake_pos[i].y * TILE_SIZE)),
					TILE_SIZE, TILE_SIZE, true, arcade::utl::Color(0, 255, 0, 255));
	}
      i++;
    }
}

void			arcade::Snake::DrawFood(const Snake &snake) const
{
  snake.graphic->drawCircle(arcade::utl::Position((snake._food_pos.x * TILE_SIZE) + (TILE_SIZE / 2),
						   (snake._food_pos.y * TILE_SIZE) + (TILE_SIZE / 2)),
			     TILE_SIZE / 2, arcade::utl::Color(51, 51, 255, 255));
}
