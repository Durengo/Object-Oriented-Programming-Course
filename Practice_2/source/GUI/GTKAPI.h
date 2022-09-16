#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class GTKAPI : public Gtk::Window
{

public:
  GTKAPI();
  ~GTKAPI() override;

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};