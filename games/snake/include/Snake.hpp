/*
** Snake.hpp for arcade in /home/pauline/rendu/cpp/cpp_arcade/src/snake
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Fri Mar 24 17:21:12 2017 Pauline Maes
// Last update Sun Apr  9 20:25:32 2017 Pauline Maes
*/

#ifndef		SNAKE_HPP_
# define	SNAKE_HPP_

#include	<array>
#include	<vector>
#include	<string>
#include	"Position.hpp"
#include	"AGame.hpp"
#include	"IGraphics.hpp"

#ifndef		MAP_SIZE
# define        MAP_SIZE 20
#endif		// MAP_SIZE

#ifndef	        HEAD_POS
# define        HEAD_POS 9
#endif		// HEAD_POS

#ifndef	        TILE_SIZE
# define        TILE_SIZE (600 / 20)
#endif		// TILE_SIZE

namespace arcade
{
  class Snake : public api::AGame
  {
   private:
    int _height;
    int _width;
    utl::Position _last_pos;
    utl::Position _food_pos;
    utl::Position _head_pos;
    std::vector<utl::Position> _snake_pos;
    int _direction;
    int _score;
    std::string		_player_name;

    void 		getMap() const;
    void		whereAmI() const;
    void	        play();
   public:
    Snake();

    ~Snake();

    bool		_game_over;

    int getHeight() const;

    int getWidth() const;

    const utl::Position & getLastPos() const;

    void setLastPos(const int x, const int y);

    const utl::Position & getFoodPos() const;

    void setFoodPos();

    std::vector<utl::Position> getSnakePos() const;

    void moveSnake();

    void incrSnake();

    int getScore() const;

    void incrScore();

    int	checkSnake();

    void play(const CommandType event);

    std::string const &	getPlayerName() const;

    void	setPlayerName(std::string const &name);

    int		play(api::IEvents const &events);

    void	goUp();

    void	goDown();

    void	goLeft();

    void	goRight();

    void	DrawMap(const arcade::Snake &) const;

    void	DrawSnake(const arcade::Snake &) const;

    void	DrawFood(const arcade::Snake &) const;

    int		init(api::IGraphic *graphic);

    int		close();

    int		restart();
  };
}


#endif		/* !SNAKE_HPP_ */
