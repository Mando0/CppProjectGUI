#include "Windows.h"

Windows::Windows(int,int,int,int,string) {
  {
    g_MainWindow = new Fl_Window(600,400,"Shop");
    g_MainWindow->box(FL_UP_BOX);
    g_MainWindow->user_data((void*)this);
    g_MainWindow->align(65);
    {
      g_MenuBar = new  Fl_Menu_Bar(0,0,600,20);
    }
    g_MainWindow->end();
  }
}
