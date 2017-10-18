//
// ACell.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 14:52:45 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//

#ifndef                ARCADE_ICell_HPP
# define                ARCADE_ICell_HPP

# include <vector>
# include "Position.hpp"
# include "Protocole.hpp"

namespace arcade
{

  class ACell
  {
   public:
    enum class CellState : uint16_t
    {
      NON_WALKABLE,
      WALKABLE,
      BORDER,
      TRAIL,
      IGNITED_TRAIL,
    };

    ACell(int x, int y) : _pos(x, y), _state(CellState::WALKABLE) {}
    ~ACell(){};

    void setState(CellState state)
    { _state = state; }

    const CellState & getState() const
    { return _state; }


   private:
    utl::Position 	_pos;
    CellState 		_state;
  };

  typedef std::vector<std::vector<ACell>> ACell_map;
}

#endif                //ARCADE_ICell_HPP
