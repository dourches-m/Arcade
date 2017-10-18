//
// QixPlayer.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 16:48:51 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//


#ifndef                ARCADE_QixPlayer_HPP
# define                ARCADE_QixPlayer_HPP

# include	"QixMap.hpp"

namespace arcade
{
  class QixMap;
}

namespace arcade
{
  class QixPlayer
  {
   public:

    enum PlayerState
    {
      ON_BORDER,
      ON_TRAIL,
      END_TRAIL
    };

    QixPlayer();
    ~QixPlayer(){}


    void 	init(const QixMap & map);
    void	go_up(QixMap &);
    void	go_down(QixMap &);
    void	go_left(QixMap &);
    void	go_right(QixMap &);

    const utl::Position &getPos() const;

   private:
    void	print_trail(QixMap &map) const;
    utl::Position _pos;
    PlayerState _playerState;
  };
}

#endif                //ARCADE_QixPlayer_HPP
