//
// Menu.hpp for Menu in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/games/menu/include
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Apr  8 15:45:14 2017 dourches
// Last update Sun Apr  9 05:40:20 2017 dourches
//

#ifndef		MENU_HPP_
# define	MENU_HPP_

# include	"IContext.hpp"
# include	"IEvents.hpp"
# include	"IGraphics.hpp"
# include	"AGame.hpp"

namespace arcade
{
  class Menu : public arcade::api::AGame
  {
    bool lr;
  public:
    Menu();
    ~Menu();

    void drawMenu() const;
    int play(arcade::api::IEvents const &event);
    int init(arcade::api::IGraphic *graphic);
    int getScore() const;
    void setPlayerName(std::string const &name);
    int	close();
    int restart();
    std::string const &getPlayerName() const;
  };
}
#endif		// MENU_HPP_
