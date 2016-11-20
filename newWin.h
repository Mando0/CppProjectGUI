#include "librarys.h"

class newWin {
  public:
    newWin(int x, int y, const char* l) : x(x), y(y), label(l) {}
    void newWinProp();
    void newWinShow();
    void createLogin();
    void createPM();
    static void loginBtnCB(Fl_Widget *w,void *v);
  private:
    int x,y;
    const char* label;
    Fl_Window *win;
    Fl_Menu_Bar *menuBar;
    Fl_Group *login, *pm;
};
