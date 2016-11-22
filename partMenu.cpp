#include "partMenu.h"

partMenu::partMenu(int x, int y, const char* label) {
  wind = new Fl_Window(x,y,label);
}

void partMenu::showPartMenuCB(Fl_Widget *w, void *v) {
  //((Fl_Group*)(w->parent()
}
