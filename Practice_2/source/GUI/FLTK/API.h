#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include <string>
#include "GUI/FLTK/Front.h"
#include "GUI/FLTK/Back.h"
#include "Person/Person.h"

class FLTKAPI : public Fl_Window
{
private:
   // GUI *instance = nullptr;
   // std::vector<Person> PersonList;
   Layer *MainLayer;

   Person *person = nullptr;

public:
   FLTKAPI(int w, int h, const char *title);
   ~FLTKAPI();
   static void Init(int resX, int resY, const std::string &title);

private:
   // static void cb_create(Fl_Widget *, void *);
   // inline void cb_copy_input();
   // static void cb_reset(Fl_Widget *, void *);
   // inline void cb_reset_data();
};