//
// QixMap.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 13:55:49 2017 Hugo Willaume
// Last update Sat Apr 8 23:10:17 2017 Hugo Willaume
//


#ifndef ARCADE_QIXMAP_HPP
#define ARCADE_QIXMAP_HPP

# include <vector>
# include "IContext.hpp"
# include "ACell.hpp"
# include "QixEnemy.hpp"

namespace arcade
{
  class QixEnemy;
}

namespace arcade
{
  class QixMap
  {
   public:
    QixMap() {};
    ~QixMap() {};

    void	init(api::IGraphic *context);
    void	draw_map(api::IGraphic *graphic) const;

    bool	exists(size_t x, size_t y) const;
    
    size_t 	getWidth(void) const;
    size_t 	getHeight(void) const;

    const ACell::CellState	&getCaseState(size_t x, size_t y) const;
    void		setCaseState(size_t x, size_t y, ACell::CellState state);

    void		fill(const arcade::QixEnemy& enemy);

   private:
    arcade::ACell_map _game_map;
    utl::Dimensions _size;
  };
}

#endif //PROJECT_QIXMAP_HPP
