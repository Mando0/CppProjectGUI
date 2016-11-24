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
  partsBtn->callback((Fl_Callback*)showPartMenuCB);
  // Create Robot Btn
  Fl_Button *robotBtn = new Fl_Button(330,150,150,50,"Create Robot");
  // Create View Parts Btn
  Fl_Button *partViewBtn = new Fl_Button(130,250,150,50,"View Parts");
  // Create View Model Btn
  Fl_Button *robotViewBtn = new Fl_Button(330,250,150,50,"View Robots");
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

void newWin::selectGroupCB(Fl_Widget *w, void *v){
  // Show group that is selected
  for (int i = 0; i < 3; i++) {
    if( i == ((Fl_Hold_Browser*)(w))->value()-1) {
      ((Fl_Group*)(w->parent()->child(i+1)))->show();
    }
    else {
      ((Fl_Group*)(w->parent()->child(i+1)))->hide();
    }
  }
}

void newWin::createPartMenu() {
  partMenu = new Fl_Group(0,30,640,480);
  partMenu->begin();
  // Sidebar Names
  tabW = new Fl_Hold_Browser(10,40,150,380);
  tabW->add("Head");
  tabW->add("Arms");
  tabW->add("Torso");
  tabW->add("Battery");
  tabW->add("Locomotor");
  tabW->select(1);

  // Info Group
  // Head Tab
  dataGroup[0] = new Fl_Group(170,40,450,380);
  dataGroup[0]->box(FL_ENGRAVED_BOX);
  dataGroup[0]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroup[0]->labelsize(24);
  hName = new Fl_Input(370,50,200,20,"Part Name:");
  hNum = new Fl_Int_Input(370,70,200,20,"Part Number:");
  hWeight = new Fl_Float_Input(370,90,200,20,"Part Weight:");
  hCost = new Fl_Float_Input(370,110,200,20,"Part Cost:");
  hDesc = new Fl_Multiline_Input(370,130,200,60,"Description:");
  dataGroup[0]->end();

  // Arm Tab
  dataGroup[1] = new Fl_Group(170,40,450,380);
  dataGroup[1]->box(FL_ENGRAVED_BOX);
  dataGroup[1]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroup[1]->labelsize(24);
  aName = new Fl_Input(370,50,200,20,"Part Name:");
  aNum = new Fl_Int_Input(370,70,200,20,"Part Number:");
  aWeight = new Fl_Float_Input(370,90,200,20,"Part Weight:");
  aCost = new Fl_Float_Input(370,110,200,20,"Part Cost:");
  aPow = new Fl_Float_Input(370,130,200,20,"Part Power:");
  aDesc = new Fl_Multiline_Input(370,150,200,60,"Description:");
  dataGroup[1]->hide();
  dataGroup[1]->end();

  // Torso Tab
  dataGroup[2] = new Fl_Group(170,40,450,380);
  dataGroup[2]->box(FL_ENGRAVED_BOX);
  dataGroup[2]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroup[2]->labelsize(24);
  lName = new Fl_Input(370,50,200,20,"Part Name:");
  lNum = new Fl_Int_Input(370,70,200,20,"Part Number:");
  lWeight = new Fl_Float_Input(370,90,200,20,"Part Weight:");
  lCost = new Fl_Float_Input(370,110,200,20,"Part Cost:");
  lBatComp = new Fl_Int_Input(370,130,200,20,"Battery Compartments:");
  lDesc = new Fl_Multiline_Input(370,150,200,60,"Description:");
  dataGroup[2]->hide();
  dataGroup[2]->end();



  // Create Init CB
  tabW->callback(selectGroupCB);
  partMenu->end();
  partMenu->hide();
}

void newWin::showPartMenuCB(Fl_Widget *w, void *v) {
  ((Fl_Group*)(w->parent()->parent()->child(2)))->hide();
  ((Fl_Group*)(w->parent()->parent()->child(3)))->show();
}
