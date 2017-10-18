//
// OpenContext.cpp for open in /home/dourches/Epitech/Seconde/CPP/cpp_arcade/lib/opengl
//
// Made by dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  Wed Apr  5 09:55:23 2017 dourches
// Last update Sat Apr  8 23:53:16 2017 dourches
//

# include	<string.h>
# include	"OpenContext.hpp"

OpenContext::OpenContext() : _name("OpenGl"), _graph(OpenGraph(*this)), _event(OpenEvent(*this))
{
}

OpenContext::~OpenContext()
{
}

static void		ret_func(const char *str, va_list ap)
{
  (void)str;
  (void)ap;
  return ;
}

void	OpenContext::init()
{
  int	i = 1;
  char *str = strdup("");

  _window.create(sf::VideoMode(800, 600), "Arcade");
  glEnable(GL_TEXTURE_2D);
  gluOrtho2D(0, 800, 600, 0);
  _window.setActive(true);
  _window.setVerticalSyncEnabled(true);
  glutInit(&i, &str);
  glutInitErrorFunc(ret_func);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

arcade::api::IGraphic	&OpenContext::getGraphic()
{
  return (_graph);
}

void		OpenContext::stop()
{
  glDisable(GL_TEXTURE_2D);
  glFlush();
  _window.setActive(false);
  _window.close();
}

void		OpenContext::clear()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void		OpenContext::display()
{
  glFlush();
  _window.display();
}

std::string const	&OpenContext::getName() const
{
  return (_name);
}

arcade::api::IEvents	&OpenContext::getEvents()
{
  return (_event);
}

sf::RenderWindow	*OpenContext::getWindow()
{
  return (&_window);
}

extern "C" arcade::api::IContext *entry_point()
{
  return new OpenContext();
}

extern "C" void delete_point(arcade::api::IContext *mod)
{
  delete mod;
}
