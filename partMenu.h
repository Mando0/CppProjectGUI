#include "librarys.h"

class partMenu {
  public:
    static void showPartMenuCB(Fl_Widget *w, void *v);
    MakeParts(int x, int y, const char* label);
  private:
    int x,y;
    const char* label;
};
