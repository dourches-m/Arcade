//
// core_loop.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Apr 5 18:1:5 2017 Hugo Willaume
// Last update Wed Apr 5 18:1:5 2017 Hugo Willaume
//

#include "Core.hpp"

void	core_loop(const std::string &first_graph)
{
  utl::Core core("./lib", "./games", first_graph);
  core.mainloop();
}
