//
// IEvents.hpp for ievent in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/includes/Wrappers
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Tue Apr  4 16:38:50 2017 dourches
// Last update Fri Apr  7 10:36:09 2017 dourches
//

#ifndef		CPP_ARCADE_IEVENTS_HPP
# define	CPP_ARCADE_IEVENTS_HPP

# include	<cstddef>
# include	<vector>
# include	"Position.hpp"
# include	"Protocole.hpp"

namespace	arcade
{
  namespace	api {
    class IEvents {
    public:

      /** Enum for keyboard keys.
       *
       */
      enum class Key : uint16_t {
	LEFT,		/*!< Left arrow		**/
	  RIGHT,		/*!< Right arrow	**/
	  UP,		/*!< Up arrow		**/
	  DOWN,		/*!< Down arrow		**/
	  ESCAPE,		/*!< Escape		**/
	  DELETE,		/*!< Backspace		**/
	  ENTER,		/*!< Carriage return	**/
	  KEY_1,		/*!< Key digit 1	**/
	  KEY_2,		/*!< Key digit 2	**/
	  KEY_3,		/*!< Key digit 3	**/
	  KEY_4,		/*!< Key digit 4	**/
	  KEY_5,		/*!< Key digit 5	**/
	  KEY_6,		/*!< Key digit 6	**/
	  KEY_7,		/*!< Key digit 7	**/
	  KEY_8,		/*!< Key digit 8	**/
	  KEY_9,		/*!< Key digit 9	**/
	  KEY_0,		/*!< Key digit 0	**/
	  CTRL,		/*!< Control		**/
	  SHIFT,		/*!< Shift 		**/
	  ALT,		/*!< Alt		**/
	  SPACE,		/*!< Space		**/
	  TAB,		/*!< Tabulation		**/
	  A,
	  B,
	  C,
	  D,
	  E,
	  F,
	  G,
	  H,
	  I,
	  J,
	  K,
	  L,
	  M,
	  N,
	  O,
	  P,
	  Q,
	  R,
	  S,
	  T,
	  U,
	  V,
	  W,
	  X,
	  Y,
	  Z,
	  UNKNOWN		/*!< Other key pressed	**/
	  };

      enum class MouseKey {
	M_BUTTON_1,        /*!< Left mouse button. */
	M_BUTTON_2,        /*!< Right mouse button. */
	M_BUTTON_3        /*!< Middle mouse button */
      };

      virtual ~IEvents()
      {}

      virtual void	pollEvents() = 0;

      /**
       * @brief Return the status of a key from keyboard.
       * @param id Key ID to check
       * @return Return true if the key if ID "id" is pressed, false otherwise
       */
      virtual bool	keyPressed(IEvents::Key id) const = 0;

      /**
       * @brief Return the status of a button from mouse
       * @param id Mouse button ID to check
       * @return Return true if the button of ID "id" is pressed, false otherwise
       */
      virtual bool	mouseButtonPressed(IEvents::MouseKey id) const = 0;

      virtual utl::Position  getMousePos() const = 0;
      virtual std::vector<Key> const &getKey() const = 0;
    };
  }
}

#endif //CPP_ARCADE_IEVENTS_HPP
