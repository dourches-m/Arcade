//
// Color.hpp for sfml in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/includes/utils
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Mon Mar 27 14:31:43 2017 dourches
// Last update Wed Mar 29 16:56:02 2017 dourches
//

#ifndef			CPP_ARCADE_COLOR_HPP_
# define		CPP_ARCADE_COLOR_HPP_

namespace		arcade
{
  namespace		utl
  {
    class		Color
    {
    public:
      union		color
      {
	struct
	{
	  unsigned char	r;
	  unsigned char	g;
	  unsigned char	b;
	  unsigned char	a;
	};
	unsigned int	color;
      }			_color;
      Color(int r, int g, int b, int a = 255)
      {
	_color.r = r;
	_color.g = g;
	_color.b = b;
	_color.a = a;
      }

      ~Color() {}
    };
  };
};

#endif			//CPP_ARCADE_COLOR_HPP_
