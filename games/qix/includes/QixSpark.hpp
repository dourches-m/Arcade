//
// QixSparks.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 16:48:32 2017 Hugo Willaume
// Last update Wed Apr 5 17:35:08 2017 Hugo Willaume
//


#ifndef                ARCADE_QixSparks_HPP
# define                ARCADE_QixSparks_HPP

# include <set>
# include <map>
# include "Position.hpp"
# include "QixMap.hpp"
# include "QixPlayer.hpp"

namespace arcade
{
  class QixSpark
  {
   public:
    QixSpark() : _pos(0, 0), _last_pos(0, 0){}
    ~QixSpark(){}

    void	init(const utl::Position &pos);
    void	seek(const QixMap &map, const QixPlayer &player);
   private:

    bool		can_go(const QixMap &map, const utl::Position &pos) const;
    void		rotate_pos(utl::Position &newpos,
				   const utl::Position present_pos,
				   const utl::Position last_pos) const;
    size_t getDirection(const QixMap &map, const QixPlayer &player,
			const utl::Position &lastpos,
			const utl::Position &present_pos,
			size_t depth) const;
    utl::Position 	_pos;
    utl::Position 	_last_pos;

  };
}

#endif                //ARCADE_QixSparks_HPP
