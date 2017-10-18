//
// main.cpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Wed Mar 22 13:27:48 2017 Hugo Willaume
// Last update Sun Apr  9 17:38:06 2017 Pauline Maes
//

#include <iostream>
#include <fstream>
#include <bits/ios_base.h>
#include <ios>
#include "Protocole.hpp"
#include "Snake.hpp"

extern "C" void Play(void)
{
  uint16_t user_command = 0;
  arcade::Snake *snake = new arcade::Snake();

  while (std::cin.read(reinterpret_cast<char *>(&user_command), sizeof(uint16_t)))
      snake->play(static_cast<arcade::CommandType>(user_command));
}

extern "C" arcade::api::AGame	*entry_point()
{
  return new arcade::Snake();
}

extern "C" void			delete_point(arcade::api::AGame *entry)
{
  delete entry;
}
