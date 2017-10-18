//
// main.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Mar 22 13:27:39 2017 Hugo Willaume
// Last update Wed Apr 5 17:35:08 2017 Hugo Willaume
//

#include <iostream>
#include <typeinfo>
#include "arcade.hpp"
#include "Core.hpp"

static bool bad_entry_point(void *handle)
{
  arcade::api::IContext *(*entry)();

  try
    {
      entry = reinterpret_cast<arcade::api::IContext *(*)()>(dlsym(handle, "entry_point"));
      (void)entry;
    }
  catch (std::bad_cast)
    {
      dlclose(handle);
      return true;
    }
  return false;
};

static bool wrong_lib(const std::string &lib_name)
{
  void	*handle;

  if ((handle = dlopen(lib_name.c_str(), RTLD_NOW)) == NULL)
    return true;
  else if (bad_entry_point(handle))
    return true;
  dlclose(handle);
  return false;
}

static int print_help()
{
  std::cout << "./arcade graphic_lib_start.so" << std::endl;
  return 1;
}


int main(int ac, char **av)
{
  if (ac != 2 || wrong_lib(av[1]))
    return print_help();
  core_loop(av[1]);
  return 0;
}