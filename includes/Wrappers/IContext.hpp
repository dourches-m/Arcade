//
// IContext.hpp for arcade in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/includes/Wrappers
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Thu Mar 30 15:22:04 2017 dourches
// Last update Mon Apr  3 16:53:38 2017 dourches
//

#ifndef ARCADE_BOOTSTRAP_IDISPLAYMODULE_HPP
#define ARCADE_BOOTSTRAP_IDISPLAYMODULE_HPP

#include "IGraphics.hpp"
#include "IEvents.hpp"
#include <string>

namespace arcade {
  namespace api {
    class IContext {
    public:

      virtual ~IContext()
      {}

      /*
       * \brief Get context to draw on -> Send to game to keep window safe
       * \return Context interface to implement (see "IGraphic.hpp")
       */
      virtual IGraphic &getGraphic() = 0;

      /*
       * \brief Initialize context -> open window and specific state for graphic lib
       */
      virtual void init() = 0;

      /*
       * \brief Destroy context
       */
      virtual void stop() = 0;

      /*
       * \brief Clear Context
       */
      virtual void clear() = 0;

      /*
       * \brief Display context
       */
      virtual void display() = 0;

      virtual std::string const &getName() const = 0;

      virtual IEvents &getEvents() = 0;

/*
    /// @brief Get object window from library
    /// @return IWindow Interface implementation of current loaded graphic library
    virtual IWindow *getWindow() = 0;

    /// @brief Pop next event in stack
    /// @return Event object containing next event from current loaded graphic library
    virtual IEvents *pollEvent() = 0;*/

    };
  }
}

#endif //ARCADE_BOOTSTRAP_IDISPLAYMODULE_HPP
