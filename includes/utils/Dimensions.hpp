//
// Dimensions.hpp for arcade in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/includes/utils
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Mon Mar 27 14:31:53 2017 dourches
// Last update Wed Mar 29 14:32:10 2017 dourches
//

#ifndef		CPP_ARCADE_DIMENSIONS_HPP_
# define	CPP_ARCADE_DIMENSIONS_HPP_

# include	<cstddef>

namespace	arcade
{
  namespace	utl
  {
    class	Dimensions
    {
    public:
      size_t	width;
      size_t	height;

      Dimensions(size_t _width = 0, size_t _height = 0) : width(_width), height(_height) {}
      ~Dimensions() {}
    };
  };
};

#endif		//CPP_ARCADE_DIMENSIONS_HPP_
