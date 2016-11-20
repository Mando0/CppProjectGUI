#include "newWin.h"

void newWin::newWinProp() {
  win = new Fl_Window(x,y,label);
  win->color(FL_WHITE);
  menuBar = new Fl_Menu_Bar(0,0,640,30);
  menuBar->add("File/Quit",0,0,0,0);
  menuBar->color(FL_WHITE);
  menuBar->box(FL_THIN_UP_BOX);
}

void newWin::newWinShow() {
  win->show();
  win->end();
}

void newWin::createLogin() {
  login = new Fl_Group(0,30,640,450);
  login->begin();
  // Title 
  Fl_Box *title = new Fl_Box(50,50,540,30);
  title->label("Robbie Robot Shop");
  title->labelcolor(FL_BLACK);
  title->labelsize(30);
  // Border
  Fl_Box *border = new Fl_Box(Fl_Boxtype::FL_FLAT_BOX,120,140,400,200,0);
  //  ID 
  Fl_Box *id = new Fl_Box(130,150,100,50);
  id->label("ID");
  id->labelcolor(FL_BLACK);
  id->labelsize(20);
  Fl_Input *idInput = new Fl_Input(250,160,180,25);
  idInput->value(NULL);
  // PIN
  Fl_Box *pin = new Fl_Box(130, 200, 100, 50);
  pin->label("PIN");
  pin->labelcolor(FL_BLACK);
  pin->labelsize(20);
  Fl_Secret_Input *pinInput = new Fl_Secret_Input(250,210,180,25);
  pinInput->value(NULL);
  // Login Btn
  Fl_Button *loginBtn = new Fl_Button(420,280,75,40,"LOGIN");
  loginBtn->callback((Fl_Callback*)loginBtnCB);
  login->end();
}

void newWin::createPM() {
  pm = new Fl_Group(0,30,640,450);
  pm->begin();
  // Title
  Fl_Box *title = new Fl_Box(50,50,540,30);
  title->label("Welcome Project Manager");
  title->labelsize(20);
  // Create Part Btn
  Fl_Button *partsBtn = new Fl_Button(130,150,150,50,"Create Parts");
  // Create Robot Btn
  Fl_Button *robotBtn = new Fl_Button(330,150,150,50,"Create Robot");
  pm->end();
  pm->hide();
}

void newWin::loginBtnCB(Fl_Widget *w,void *v) {
  if(strcmp(((Fl_Input*)(w->parent()->child(3)))->value(),"123") == 0
    && strcmp(((Fl_Input*)(w->parent()->child(5)))->value(),"123") == 0) {
      ((Fl_Group*)(w->parent()))->hide();
      ((Fl_Group*)(w->parent()->parent()->child(2)))->show();
  }
}
