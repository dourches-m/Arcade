//
// QixMap.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 14:11:27 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//

#include "QixMap.hpp"

void	arcade::QixMap::init(api::IGraphic *context)
{
  utl::Dimensions	graph_size;

  graph_size = context->getDimensions();
  if (_game_map.size() == 0)
    graph_size = utl::Dimensions(20, 20);
  for (size_t y = 0; y < graph_size.height; y++)
    {
      for (size_t x = 0; x < graph_size.width; x++)
	{
	  _game_map[y].emplace_back(x, y);
	  if (y == 0 || x == 0 || x + 1 == graph_size.width
	      || y + 1 == graph_size.height)
	    _game_map[y][x].setState(ACell::CellState::BORDER);
	}
    }
  _size = graph_size;
}

size_t 	arcade::QixMap::getWidth(void) const
{  return _size.width; }

size_t 	arcade::QixMap::getHeight(void) const
{  return _size.height; }

bool	arcade::QixMap::exists(size_t x, size_t y) const
{
  if (x < _size.width && y < _size.height)
    return true;
  return false;
}

const arcade::ACell::CellState	&arcade::QixMap::getCaseState(size_t x, size_t y) const
{  return _game_map[y][x].getState(); }

void	arcade::QixMap::setCaseState(size_t x, size_t y, ACell::CellState state)
{  _game_map[y][x].setState(state); }


void	arcade::QixMap::fill(const arcade::QixEnemy& enemy)
{
  (void)enemy;
}

void	arcade::QixMap::draw_map(api::IGraphic *graphic) const
{
  (void)graphic;
}
