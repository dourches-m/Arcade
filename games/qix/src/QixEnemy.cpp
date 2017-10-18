//
// QixEnemy.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 21:59:29 2017 Hugo Willaume
// Last update Wed Apr 5 21:59:29 2017 Hugo Willaume
//


#include <set>
#include "QixEnemy.hpp"

arcade::QixEnemy::QixEnemy() : _size(0, 0), _pos(0, 0)
{

}

void arcade::QixEnemy::init(const QixMap &map)
{
  _size.width = map.getWidth() / 6;
  _size.height = map.getWidth() / 6;
  _pos.x = map.getWidth() - (_size.width / 2);
  _pos.y = map.getHeight() - (_size.height / 2);
  _nb_moves = 0;
}

bool arcade::QixEnemy::illegal_move(arcade::QixMap &map, utl::Position next_move) const
{
  utl::Position new_pos(0, 0);
  static std::set<ACell::CellState> permitted_states {ACell::CellState::WALKABLE,
						      ACell::CellState::TRAIL,
						      ACell::CellState::IGNITED_TRAIL};


  new_pos.x = _pos.x + next_move.x;
  new_pos.y = _pos.y + next_move.y;
  for (size_t y = new_pos.y; y < new_pos.y + _size.height; y++)
    {
      for (size_t x = new_pos.x; x < new_pos.x + _size.width; x++)
	{
	  if (permitted_states.count(map.getCaseState(x, y)))
	    return true;
	}
    }
  return false;
}


void arcade::QixEnemy::move(arcade::QixMap &map)
{
  utl::Position next_move(0, 0);

  if (_nb_moves <= 0)
    {
      _nb_moves += rand() % 4;
      _card_dir = static_cast<CardDir>(rand() % 4);
    }
  switch (_card_dir)
  {
    case(NORTH) :
      {
	next_move.x += rand() % 2;
	next_move.y += rand() % 3 - 1;
	break;
      }
    case(SOUTH) :
      {
	next_move.x += rand() % 2;
	next_move.y += rand() % 3 - 1;
	break;
      }
    case(EAST) :
      {
	next_move.x += rand() % 3 - 1;
	next_move.y += rand() % 2;
	break;
      }
    case(WEST) :
      {
	next_move.x += rand() % 3 - 1;
	next_move.y += rand() % 2;
	break;
      }
  }
  if (illegal_move(map, next_move))
    move(map);
  else
    {
      _nb_moves--;
      _pos.x += next_move.x;
      _pos.y += next_move.y;
    }
}