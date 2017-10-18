//
// Core.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 17:52:21 2017 Hugo Willaume
// Last update Sun Apr  9 22:38:41 2017 maes_p
//

#include <unistd.h>
#include "Core.hpp"

utl::Core::Core(const std::string &lib_path, const std::string &game_path,
		const std::string &first_lib) : _context(NULL), _game(NULL)
{
  _libLoader.add_directory(lib_path);
  _gameLoader.add_directory(game_path);
  _context = _libLoader.getEntryResult(first_lib.substr(first_lib.rfind("lib")));
  _game = _gameLoader.getEntryResult("libarcade_menu.so");
}

utl::Core::~Core()
{
}

void utl::Core::shutdown()
{
  std::cerr << "Shutting down" << std::endl;
  _game->close();
  _context->stop();
  _gameLoader.exitLib(_game);
  _libLoader.exitLib(_context);
  _context = NULL;
  _game = NULL;
}

void utl::Core::other_lib(int next)
{
  std::cerr << "Loading other lib" << std::endl;
  _context->stop();
  _context =_libLoader.other_lib(_context, next);
  std::cerr << "Initialising new context " << std::endl;
  _context->init();
  std::cerr << "Getting other lib events" << std::endl;
  _events = &_context->getEvents();
  std::cerr << "Finished loading other lib" << std::endl;
  _game->setGraphicModule(&_context->getGraphic());
}

void utl::Core::other_game(int next)
{
  std::cerr << "Loading other game" << std::endl;
  _game->close();
  _game = _gameLoader.other_lib(_game, next);
  _game->init(&_context->getGraphic());
  if (_game->getName() == "Menu")
    other_game(next);
}

void utl::Core::load_menu()
{
  std::cerr << "Loading menu" << std::endl;
  _gameLoader.exitLib(_game);
  _game = _gameLoader.getEntryResult("libarcade_menu.so");
  _game->init(&_context->getGraphic());

}

bool utl::Core::catch_core_events()
{
  bool		event_catched = true;

  if (_events->keyPressed(arcade::api::IEvents::Key::ESCAPE))
    this->shutdown();
  else if (_events->keyPressed(arcade::api::IEvents::Key::KEY_2))
    this->other_lib(-1);
  else if (_events->keyPressed(arcade::api::IEvents::Key::KEY_3))
    this->other_lib(1);
  else if (_events->keyPressed(arcade::api::IEvents::Key::KEY_4))
    this->other_game(-1);
  else if (_events->keyPressed(arcade::api::IEvents::Key::KEY_5))
    this->other_game(1);
  else if (_events->keyPressed(arcade::api::IEvents::Key::KEY_8))
    _game->restart();
  else if (_events->keyPressed(arcade::api::IEvents::Key::KEY_9))
    this->load_menu();
  else
    event_catched = false;
  return event_catched;
}

void utl::Core::mainloop()
{
  _context->init();
  _events = &_context->getEvents();
  _game->init(&(_context->getGraphic()));
  while (_game)
    {
      _events->pollEvents();
      if (!this->catch_core_events())
	{
	  usleep(150000);
	  _context->clear();
	  _game->play(*_events);
	  _context->display();
	}
    }
}
