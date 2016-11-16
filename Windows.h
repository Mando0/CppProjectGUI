#include "GUI.H"

class Windows {
  public:
    Windows(int x, int y, int width, int height, string title); 
    Fl_Window *g_MainWindow;
    Fl_Menu_Bar *g_MenuBar;
};
    
