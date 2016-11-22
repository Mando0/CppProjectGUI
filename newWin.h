#include "librarys.h"

class newWin {
  public:
    newWin(int x, int y, const char* l) : x(x), y(y), label(l) {}
    void newWinProp();
    void newWinShow();
    void createLogin();
    void createPM();
    void createPartMenu();
    static void loginBtnCB(Fl_Widget *w,void *v);
    static void showPartMenuCB(Fl_Widget *w, void *v);
  private:
    int x,y;
    const char* label;
    Fl_Window *win;
    Fl_Menu_Bar *menuBar;
    Fl_Group *login, *pm, *partMenu, *dataGroup[5] = {0,0,0,0,0};
    Fl_Hold_Browser *tabW;
    Fl_Input *hName;
    Fl_Int_Input *hNum;
    Fl_Float_Input *hWeight, *hCost;
    Fl_Multiline_Input *hDesc;
};
