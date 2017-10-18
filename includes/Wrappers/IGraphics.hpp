//
// IGraphics.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Mar 22 14:10:07 2017 Hugo Willaume
// Last update Sun Apr  9 09:34:37 2017 dourches
//

#ifndef		CPP_ARCADE_IGRAPHIC_HPP
# define	CPP_ARCADE_IGRAPHIC_HPP

# include	<string>
# include	<cstddef>
# include	"Position.hpp"
# include	"Dimensions.hpp"
# include	"Color.hpp"

namespace arcade {
  enum		TextureID
    {
      WALL = 1,
      PLAYER_HEAD,
      PLAYER_BODY,
      SHOT,
      ENEMY,
      POWERUP
    };

  namespace api {

    class IGraphic {
    public:
      virtual ~IGraphic() {}

      virtual void drawLine(arcade::utl::Position const &from, arcade::utl::Position const &to, arcade::utl::Color const &color) = 0;
      virtual void drawRectangle(arcade::utl::Position const &from, size_t width, size_t height, bool fill, arcade::utl::Color const &color) = 0;
      virtual void drawCircle(arcade::utl::Position const &pos, size_t radius, arcade::utl::Color const &color) = 0;
      virtual void drawSprite(arcade::utl::Position const &pos, arcade::TextureID texture_id, arcade::utl::Color const &color) = 0;
      virtual void drawText(arcade::utl::Position const &pos, std::string const &text, arcade::utl::Color const &color) = 0;
      virtual arcade::utl::Dimensions const &getDimensions() const = 0;
      virtual int loadSprite(TextureID id, std::string const &file, utl::Position const &pos, utl::Dimensions const &dimensions) = 0;
      virtual void unloadSprites() = 0;
    };
  }
}

#endif //CPP_ARCADE_IGRAPHIC_HPP
