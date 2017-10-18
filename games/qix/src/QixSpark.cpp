/*
** QixSparks.cpp for arcade in /home/hurlu/rendu/
**
** Made by Hugo Willaume
** Login   <hugo.willaume@epitech.eu>
**
** Started on  Sun Apr 9 15:24:25 2017 Hugo Willaume
** Last update Sun Apr 9 15:24:25 2017 Hugo Willaume
*/

#include "QixSpark.hpp"

void	arcade::QixSpark::init(const utl::Position &pos)
{
  _pos = pos;
}

void		arcade::QixSpark::rotate_pos(utl::Position &newpos,
					     const utl::Position present_pos,
						 const utl::Position last_pos) const
{
  if (newpos.x == present_pos.x - 1)
    {
      newpos.x = present_pos.x;
      newpos.y = present_pos.y -1;
    }
  else if (newpos.y == present_pos.y - 1)
    {
      newpos.x = present_pos.x + 1;
      newpos.y = present_pos.y;
    }
  else if (newpos.x == present_pos.x + 1)
    {
      newpos.x = present_pos.x;
      newpos.y = present_pos.y + 1;
    }
  else if (newpos.x == present_pos.y + 1)
    {
      newpos.x = present_pos.x - 1;
      newpos.y = present_pos.y;
    }
  if (newpos.x == last_pos.x && newpos.y == last_pos.y)
    rotate_pos(newpos, present_pos, last_pos);
}

bool		arcade::QixSpark::can_go(const QixMap &map, const utl::Position &pos) const
{
  static std::set<ACell::CellState> spark_walk = {ACell::CellState::BORDER,
						  ACell::CellState::TRAIL,
						  ACell::CellState::IGNITED_TRAIL};

  if (map.exists(pos.x, pos.y) &&
      spark_walk.count(map.getCaseState(pos.x, pos.y)))
    return true;
  return false;
}

size_t arcade::QixSpark::getDirection(const QixMap &map, const QixPlayer &player,
				      const utl::Position &lastpos,
				      const utl::Position &present_pos,
				      size_t depth) const
{
  utl::Position new_pos(present_pos.x + present_pos.x - lastpos.x,
			present_pos.y + present_pos.y - lastpos.y);

  for (int i = 0; i < 2; i++)
    {
      if (new_pos.x == player.getPos().x && new_pos.y == player.getPos().y)
	return depth;
      else if (can_go(map, new_pos))
	getDirection(map, player, present_pos, new_pos, depth + 1);
      else
	rotate_pos(new_pos, present_pos, lastpos);

    }
  return -1;
}

void	arcade::QixSpark::seek(const QixMap &map, const QixPlayer &player)
{
  std::map<size_t, utl::Position> depth_map;
  utl::Position	candidate_pos(0, 1);

  (void)map;
  (void)player;
  for (int i = 0; i < 3; i++)
    {
    }

}