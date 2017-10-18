//
// Core.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 17:41:38 2017 Hugo Willaume
// Last update Sun Apr  9 22:38:31 2017 maes_p
//


#ifndef                ARCADE_Core_HPP
# define                ARCADE_Core_HPP

# include <vector>
# include "DLLoader.hpp"
# include "IContext.hpp"
# include "AGame.hpp"

namespace utl
{
    class Core
    {
     public:
      Core(const std::string &lib_path,
	   const std::string &game_path,
	   const std::string &first_lib);
      ~Core();

      bool catch_core_events();
      void mainloop();
      void shutdown();
      void other_lib(int);
      void other_game(int);
      void load_menu();
     private:

      DLLoader<arcade::api::IContext> _libLoader;
      arcade::api::IContext *_context;

      DLLoader<arcade::api::AGame> _gameLoader;
      arcade::api::AGame *_game;

      arcade::api::IEvents *_events;
    };
}

#endif                //ARCADE_Core_HPP
