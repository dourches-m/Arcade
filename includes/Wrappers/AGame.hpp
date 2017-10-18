//
// AGame.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Mon Mar 13 09:04:43 2017 Hugo Willaume
// Last update Fri Apr  7 18:51:40 2017 Pauline Maes
//


#ifndef CPP_ARCADE_AGAME_HPP
# define CPP_ARCADE_AGAME_HPP

# include <iostream>
# include <string>
# include "IEvents.hpp"
# include "IGraphics.hpp"

namespace arcade
{

  namespace api {

    class AGame
    {
    protected:
      IGraphic		*graphic;
      std::string	_name;
      std::string	_player_name;

    public:
      virtual 		~AGame() {};

    public:
      AGame() : graphic(0) {};

      void		setGraphicModule(IGraphic *module)
      {
	graphic = module;
      }

      void		setName(std::string const &name)
      {
	_name = name;
      }

      std::string const	&getName() const
      {
	return _name;
      }

      virtual int	init(IGraphic *graphic) = 0;
      virtual int	play(IEvents const &event) = 0;
      virtual int	close() = 0;
      virtual int	restart() = 0;
      virtual int	getScore() const = 0;

      virtual void	setPlayerName(std::string const &name) = 0;
      virtual std::string const &getPlayerName() const = 0;
    };
  }


}


#endif //CPP_ARCADE_AGAME_HPP
