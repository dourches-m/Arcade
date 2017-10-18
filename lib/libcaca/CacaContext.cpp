//
// CacaContext.cpp for caca in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/sfml
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Thu Mar 30 13:56:44 2017 dourches
// Last update Sat Apr  8 22:46:33 2017 dourches
//

#include	"CacaContext.hpp"


CacaContext::CacaContext() : _name("LibCaca"), _graph(CacaGraph(*this)), _event(CacaEvent(*this))
{
}

CacaContext::~CacaContext()
{
}

void CacaContext::init()
{
  _canvas = caca_create_canvas(80, 60);
  if (_canvas == NULL)
    {
      std::cerr << "libcaca can't initialize window" << std::endl;
      exit(1);
    }
  _display = caca_create_display(_canvas);
  caca_set_display_title(_display, "Arcade");
}

void CacaContext::stop()
{
  std::cerr << "Closing libcaca's context" << std::endl;
  caca_free_display(_display);
  caca_free_canvas(_canvas);
}

void CacaContext::clear()
{
  caca_clear_canvas(_canvas);
}

void CacaContext::display()
{
  caca_set_color_argb(_canvas, 0x0000000, 0x0000000);
  caca_refresh_display(_display);
}

arcade::api::IGraphic &CacaContext::getGraphic()
{
  return (_graph);
}

std::string const &CacaContext::getName() const
{
  return (_name);
}

arcade::api::IEvents &CacaContext::getEvents()
{
  return (_event);
}


caca_canvas_t *CacaContext::getCanvas()
{
  return (_canvas);
}

caca_display_t *CacaContext::getDisplay()
{
  return (_display);
}

extern "C" arcade::api::IContext *entry_point()
{
  return new CacaContext();
}

extern "C" void delete_point(arcade::api::IContext *mod)
{
  delete mod;
}
