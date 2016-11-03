#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Menu.H"
#include "FL/Fl_Menu_Bar.H"
#include "FL/Fl_Menu_Item.H"
#include "FL/Fl_Input.H"

void create_parts_cb(Fl_Widget*, void* v);

int main() {
  Fl_Window *win = new Fl_Window(640,480,"Robbie Robot Shop");
  Fl_Menu_Bar *menu_bar = new Fl_Menu_Bar(0,0,640,30);
  Fl_Menu_Item menuitem[] = {{"&File", 0,0,0,FL_SUBMENU},{"&Create Parts",0,(Fl_Callback *)create_parts_cb},{0},{0}};
  menu_bar->copy(menuitem);
  win->end();
  win->show();

  return Fl::run();
}

void create_parts_cb(Fl_Widget*, void* v) {
}
