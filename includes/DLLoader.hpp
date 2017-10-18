//
// DLLoader.hpp for arcade in /home/hurlu/rendu/
//
// Made by Hugo Willaume
// Login   <hugo.willaume@epitech.eu>
//
// Started on  Tue Apr 4 16:37:36 2017 Hugo Willaume
// Last update Sun Apr  9 18:54:02 2017 dourches
//


#ifndef                ARCADE_DLLoader_HPP
# define                ARCADE_DLLoader_HPP

# include <string>
# include <map>
# include <iostream>
# include <dirent.h>
# include <dlfcn.h>

namespace utl
{
  template <class T>
  class DLLoader
  {
   public:
    DLLoader() : _context_loaded("") {}

    ~DLLoader() {
      for (auto it : _handles_map)
	dlclose(it.second);
    }

    void add_directory(const std::string &directory_name)
    {
      DIR		*dir;
      struct dirent	*dir_struct;
      std::string	file_name;
      void		*handle;

      dir = opendir(directory_name.c_str());
      while ((dir_struct = readdir(dir)) != NULL)
	{
	  file_name = std::string(dir_struct->d_name);
	  if (file_name.compare(0, 3, "lib") == 0 &&
	      file_name.compare(file_name.size() - 3, 3, ".so") == 0)
	    {
	      handle = dlopen((directory_name + "/" + file_name).c_str(), RTLD_NOW | RTLD_GLOBAL);
	      if (handle != NULL)
		{
		  _handles_map.insert(std::pair<std::string, void *>(dir_struct->d_name, handle));
		  std::cerr << "Loading " << dir_struct->d_name << " at " << handle << std::endl;
		}
	      else
		std::cerr << "Opening error in " << dlerror() << std::endl;
	    }
	}
      closedir(dir);
    }

    T *getEntryResult(const std::string &lib_name)
    {
      T *(*funcptr)();

      if (_context_loaded != "")
	{
	  std::cerr << "A library is already loaded :(" << std::endl;
	  return NULL;
	}
      for (auto it : _handles_map)
	{
	  if (it.first == lib_name)
	    {
	      funcptr = reinterpret_cast<T *(*)()>(dlsym(it.second, "entry_point"));
	      _context_loaded = lib_name;
	      std::cerr << "Loading " << lib_name << "..." << std::endl;
	      return funcptr();
	    }

	}
      return NULL;
    }

    T *other_lib(T *lib, int next)
    {
      auto 		found_it = _handles_map.find(_context_loaded);
      auto		next_it = _handles_map.begin();
      std::string	new_context = "";

      ++next_it;
      if (next_it->first == _handles_map.begin()->first)
	std::cerr << "WHAT THE ACTUAL FEUUUUUUUUUUUUUUUUUUUUCK" << std::endl;
      if  (next == -1 && found_it == _handles_map.begin())
	new_context = _handles_map.rbegin()->first;
      else if (next == 1 && found_it == --_handles_map.end())
	new_context = _handles_map.begin()->first;
      else
	{
	  for (auto it = _handles_map.begin(); it != _handles_map.end(); ++it)
	    {
	      if (next == 1 && it == found_it)
		new_context = next_it->first;
	      else if (next == -1 && next_it == found_it)
		new_context = it->first;
	      if (next_it != _handles_map.end())
		next_it++;
	    }
	}
      exitLib(lib);
      //      std::cerr << "Just loaded " << new_context << " at address " << _handles_map.find(_context_loaded)->second << std::endl;
      return getEntryResult(new_context);
    }

    void exitLib(T *context) {
      _context_loaded = "";
      delete context;
    }

   private:
    DLLoader(const DLLoader &);

    DLLoader *operator=(const DLLoader &);

    std::string	_context_loaded;
    std::map<const std::string, void *> _handles_map;

  };

}

#endif                //ARCADE_DLLoader_HPP
