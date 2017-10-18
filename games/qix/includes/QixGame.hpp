//
// QixGame.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 11:57:30 2017 Hugo Willaume
// Last update Wed Apr 5 15:25:39 2017 Hugo Willaume
//


#ifndef                ARCADE_QixGame_HPP
# define                ARCADE_QixGame_HPP

# include <string>
# include <vector>
# include "IContext.hpp"
# include "AGame.hpp"
# include "QixEnemy.hpp"
# include "QixPlayer.hpp"
# include "QixSpark.hpp"
# include "QixMap.hpp"

namespace arcade
{
  class QixGame : public arcade::api::AGame
  {
   public:
    QixGame();
    ~QixGame();

    virtual int			init(api::IGraphic *graphic);
    virtual int			play(const api::IEvents&);
    virtual void *play(arcade::CommandType event);
    virtual int			close();
    virtual int			restart();
    virtual int 		getScore() const;
    virtual void		setPlayerName(std::string const &name);
    virtual std::string const	&getPlayerName() const;

    struct WhereAmI			*where_am_i() const;
    struct GetMap			*get_map() const;

   private:
    std::string	_name;
    bool	_game_over;
    int		_score;

    QixEnemy			_enemy;
    std::vector<QixSpark>	_sparks;
    QixPlayer			_player;
    QixMap			_map;
  };
}

#endif                //ARCADE_QixGame_HPP
