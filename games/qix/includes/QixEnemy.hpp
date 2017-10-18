//
// QixEnemy.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 16:48:11 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//

#ifndef                ARCADE_QixEnemy_HPP
# define                ARCADE_QixEnemy_HPP

#include "QixMap.hpp"

namespace arcade
{
  class QixMap;
}

namespace arcade
{
  class QixEnemy
  {
   public:
    enum CardDir{
      NORTH,
      SOUTH,
      WEST,
      EAST
    };

    QixEnemy();
    ~QixEnemy(){};

    void	init(const QixMap &map);
    void	move(QixMap &map);
   private:
    bool 	illegal_move(QixMap &map, utl::Position next_move) const;

    utl::Dimensions _size;
    utl::Position _pos;
    size_t 	_nb_moves;
    CardDir 	_card_dir;
  };
}

#endif                //ARCADE_QixEnemy_HPP
