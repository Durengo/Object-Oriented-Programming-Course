#include "source/Console.h"

#include <fmt/core.h>

// https://calculat.io/en/date

// int main()
// {
//   // test();
//   mainLoop();

//   return 0;
// }

#include "source/GUI/GTKAPI.h"
#include <gtkmm/application.h>

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples");
  

  return app->make_window_and_run<GTKAPI>(argc, argv);
}