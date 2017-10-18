//
// QixPlayer.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 21:54:42 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//

#include "QixPlayer.hpp"

arcade::QixPlayer::QixPlayer() : _pos(0, 0) ,
				 _playerState(ON_BORDER)
{
}

void 	arcade::QixPlayer::init(const QixMap & map)
{
  _pos.x = map.getWidth() / 2;
  _pos.y = map.getHeight() - 1;
}

void	arcade::QixPlayer::print_trail(QixMap &map) const
{
  if (_playerState == ON_TRAIL)
    map.setCaseState(_pos.x, _pos.y, ACell::CellState::TRAIL);
}

void	arcade::QixPlayer::go_up(QixMap &map)
{
  ACell::CellState future_state;

  if (!map.exists(_pos.x, _pos.y - 1) ||
      ((future_state = map.getCaseState(_pos.x, _pos.y - 1)) != ACell::CellState::WALKABLE
       && future_state != ACell::CellState::BORDER))
    return ;
  if (_playerState == ON_BORDER && future_state == ACell::CellState::WALKABLE)
    _playerState = ON_TRAIL;
  else if (_playerState == ON_TRAIL && future_state == ACell::CellState::BORDER)
    _playerState = END_TRAIL;
  _pos.y -= 1;
  print_trail(map);
}

void	arcade::QixPlayer::go_down(QixMap &map)
{
  ACell::CellState future_state;

  if (!map.exists(_pos.x, _pos.y + 1) ||
      ((future_state = map.getCaseState(_pos.x, _pos.y + 1)) != ACell::CellState::WALKABLE
       && future_state != ACell::CellState::BORDER))
    return ;
  if (_playerState == ON_BORDER && future_state == ACell::CellState::WALKABLE)
    _playerState = ON_TRAIL;
  else if (_playerState == ON_TRAIL && future_state == ACell::CellState::BORDER)
    _playerState = END_TRAIL;
  _pos.y += 1;
  print_trail(map);
}

void	arcade::QixPlayer::go_left(QixMap &map)
{
  ACell::CellState future_state;

  if (!map.exists(_pos.x - 1, _pos.y) ||
      ((future_state = map.getCaseState(_pos.x - 1, _pos.y)) != ACell::CellState::WALKABLE
       && future_state != ACell::CellState::BORDER))
    return ;
  if (_playerState == ON_BORDER && future_state == ACell::CellState::WALKABLE)
    _playerState = ON_TRAIL;
  else if (_playerState == ON_TRAIL && future_state == ACell::CellState::BORDER)
    _playerState = END_TRAIL;
  _pos.x -= 1;
  print_trail(map);
}

void	arcade::QixPlayer::go_right(QixMap &map)
{
  ACell::CellState future_state;

  if (!map.exists(_pos.x + 1, _pos.y) ||
      ((future_state = map.getCaseState(_pos.x + 1, _pos.y)) != ACell::CellState::WALKABLE
       && future_state != ACell::CellState::BORDER))
    return ;
  if (_playerState == ON_BORDER && future_state == ACell::CellState::WALKABLE)
    _playerState = ON_TRAIL;
  else if (_playerState == ON_TRAIL && future_state == ACell::CellState::BORDER)
    _playerState = END_TRAIL;
  _pos.x += 1;
  print_trail(map);
}

const arcade::utl::Position &arcade::QixPlayer::getPos() const
{
  return _pos;
}