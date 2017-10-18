//
// Position.hpp for arcade in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/includes/utils
//
// Made by dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  Mon Mar 27 14:32:02 2017 dourches
// Last update Wed Mar 29 14:32:34 2017 dourches
//

#ifndef		CPP_ARCADE_POSITION_HPP_
# define	CPP_ARCADE_POSITION_HPP_

# include	<cstddef>

namespace	arcade
{
  namespace	utl
  {
    class	Position
    {
    public:
      size_t	x;
      size_t	y;

      Position(size_t _x = 0, size_t _y = 0) : x(_x), y(_y) {}
      ~Position() {}
    };
  };
};

#endif		//CPP_ARCADE_POSITION_HPP_
