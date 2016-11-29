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
  partViewBtn->callback((Fl_Callback*)partViewCB);
  // Create View Model Btn
  Fl_Button *robotViewBtn = new Fl_Button(330,250,150,50,"View Robots");
  // Create Logout Btn
  Fl_Button *logoutBtn = new Fl_Button(10,440,200,30,"Logout");
  logoutBtn->callback((Fl_Callback*)logoutBtnCB);
  pm->end();
  pm->hide();
}

void newWin::partViewCB(Fl_Widget *w, void*){
  ((Fl_Group*)(w->parent()->parent()->child(2)))->hide();
  ((Fl_Group*)(w->parent()->parent()->child(4)))->show();
}

void newWin::partView() {
  // Load vector 
  ifstream infile("info.txt");
  string line;
  while(getline(infile,line)) {
    istringstream iss(line);
    string a1;
    int c;
    iss >> c >> a1;
    switch(c) {
      case 1:
        h.set_name(a1);
        head.push_back(h);
        break;
      case 2:
        a.set_name(a1);
        arm.push_back(a);
        break;
      case 3:
        t.set_name(a1);
        torso.push_back(t);
        break;
      case 4:
        b.set_name(a1);
        battery.push_back(b);
        break;
      case 5:
        l.set_name(a1);
        locomotor.push_back(l);
        break;
    }
  }

  partMenu = new Fl_Group(0,30,640,450);
  partMenu->begin();
  // Part List
  tab1 = new Fl_Hold_Browser(10,40,130,380); 
  tab1->add("Head");
  tab1->add("Arms");
  tab1->add("Torso");
  tab1->add("Battery");
  tab1->add("Locomotor");
  tab1->select(1);

  // Part List 2
  tab2 = new Fl_Hold_Browser(150,40,130,380);
  tab2->clear();
  for(int i = 0; i < head.size(); i++) {
    tab2->add(head[i].get_name().c_str());
  }
  
  tab1->callback(selectPartCB,this);

  // Back Button
  Fl_Button *backBtn = new Fl_Button(10,430,150,30,"Back");
  backBtn->callback(backBtnCB);
  partMenu->end();
  partMenu->hide();
}

void newWin::selectPartCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->selectPart(w);
}

void newWin::selectPart(Fl_Widget *w) {
int i = tab1->value();
  switch(i) { 
    case 1:
      tab2->clear();
      for(int i = 0; i < head.size(); i++) {
        tab2->add(head[i].get_name().c_str());
      }
      break;
    case 2:
      tab2->clear();
      for(int i = 0; i < arm.size(); i++) {
        tab2->add(arm[i].get_name().c_str());
      }
      break;
    case 3:
      tab2->clear();
      for(int i = 0; i < torso.size(); i++) {
        tab2->add(torso[i].get_name().c_str());
      }
      break;
    case 4:
      tab2->clear();
      for(int i = 0; i < battery.size(); i++) {
        tab2->add(battery[i].get_name().c_str());
      }
      break;
    case 5:
      tab2->clear();
      for(int i = 0; i < locomotor.size(); i++) {
        tab2->add(locomotor[i].get_name().c_str());
      }
      break;
    default:
      break;
  }
}


void newWin::logoutBtnCB(Fl_Widget *w, void *v) {
  ((Fl_Group*)(w->parent()))->hide();
  ((Fl_Group*)(w->parent()->parent()->child(1)))->show();
}

void newWin::loginBtnCB(Fl_Widget *w,void *v) {
  if(strcmp(((Fl_Input*)(w->parent()->child(3)))->value(),"123") == 0
    && strcmp(((Fl_Input*)(w->parent()->child(5)))->value(),"123") == 0) {
      ((Fl_Input*)(w->parent()->child(3)))->value("");
      ((Fl_Input*)(w->parent()->child(5)))->value("");
      ((Fl_Group*)(w->parent()))->hide();
      ((Fl_Group*)(w->parent()->parent()->child(2)))->show();
  }
}

void newWin::selectGroupCB(Fl_Widget *w, void *v){
  // Show group that is selected
  for (int i = 0; i < 5; i++) {
    if( i == ((Fl_Hold_Browser*)(w))->value()-1) {
      ((Fl_Group*)(w->parent()->child(i+1)))->show();
    }
    else {
      ((Fl_Group*)(w->parent()->child(i+1)))->hide();
    }
  }
}

void newWin::saveHeadCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->saveHead(w);
}

void newWin::saveHead(Fl_Widget *w) {
  ofstream partsinfo("info.txt",ios_base::out|ios_base::app);
  partsinfo << "1 ";
  partsinfo << hName->value() << " ";
  partsinfo << hNum->value() << " ";
  partsinfo << hWeight->value() << " ";
  partsinfo << hCost->value() << " ";
  partsinfo << hDesc->value() << " ";
  partsinfo << '\n';
  partsinfo.close();
  hName->value("");
  hNum->value("");
  hWeight->value("");
  hCost->value("");
  hDesc->value("");
}

void newWin::saveArmCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->saveArm(w);
}

void newWin::saveArm(Fl_Widget *w) {
  ofstream partsinfo("info.txt",ios_base::out|ios_base::app);
  partsinfo << "2 ";
  partsinfo << aName->value();
  partsinfo << " ";
  partsinfo << '\n';
  partsinfo.close();
  aName->value("");
}

void newWin::saveTorsoCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->saveTorso(w);
}

void newWin::saveTorso(Fl_Widget *w) {
  ofstream partsinfo("info.txt",ios_base::out|ios_base::app);
  partsinfo << "3 ";
  partsinfo << tName->value();
  partsinfo << " ";
  partsinfo << '\n';
  partsinfo.close();
  tName->value("");
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
  Fl_Button *hCreate = new Fl_Button(370,350,200,60,"Create");
  hCreate->callback(saveHeadCB,this);
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
  Fl_Button *aCreate = new Fl_Button(370,350,200,60,"Create");
  aCreate->callback(saveArmCB,this);
  dataGroup[1]->hide();
  dataGroup[1]->end();

  // Torso Tab
  dataGroup[2] = new Fl_Group(170,40,450,380);
  dataGroup[2]->box(FL_ENGRAVED_BOX);
  dataGroup[2]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroup[2]->labelsize(24);
  tName = new Fl_Input(370,50,200,20,"Part Name:");
  tNum = new Fl_Int_Input(370,70,200,20,"Part Number:");
  tWeight = new Fl_Float_Input(370,90,200,20,"Part Weight:");
  tCost = new Fl_Float_Input(370,110,200,20,"Part Cost:");
  tBatComp = new Fl_Int_Input(370,130,200,20,"Battery Compartments:");
  tDesc = new Fl_Multiline_Input(370,150,200,60,"Description:");
  Fl_Button *tCreate = new Fl_Button(370,350,200,60,"Create");
  tCreate->callback(saveTorsoCB,this);
  dataGroup[2]->hide();
  dataGroup[2]->end();

  // Battery Tab
  dataGroup[3] = new Fl_Group(170,40,450,380);
  dataGroup[3]->box(FL_ENGRAVED_BOX);
  dataGroup[3]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroup[3]->labelsize(24);
  bName = new Fl_Input(370,50,200,20,"Part Name:");
  bNum = new Fl_Int_Input(370,70,200,20,"Part Number:");
  bWeight = new Fl_Float_Input(370,90,200,20,"Part Weight:");
  bCost = new Fl_Float_Input(370,110,200,20,"Part Cost:");
  bTotalEng = new Fl_Int_Input(370,130,200,20,"Total Energy:");
  bDesc = new Fl_Multiline_Input(370,150,200,60,"Description:");
  Fl_Button *bCreate = new Fl_Button(370,350,200,60,"Create");
  dataGroup[3]->hide();
  dataGroup[3]->end();

  // Locomotor Tab
  dataGroup[4] = new Fl_Group(170,40,450,380);
  dataGroup[4]->box(FL_ENGRAVED_BOX);
  dataGroup[4]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroup[4]->labelsize(24);
  lName = new Fl_Input(370,50,200,20,"Part Name:");
  lNum = new Fl_Int_Input(370,70,200,20,"Part Number:");
  lWeight = new Fl_Float_Input(370,90,200,20,"Part Weight:");
  lCost = new Fl_Float_Input(370,110,200,20,"Part Cost:");
  lMaxSpd = new Fl_Int_Input(370,130,200,20,"Max Speed:");
  lPwrCons = new Fl_Int_Input(370,150,200,20,"Power Consumed:");
  lDesc = new Fl_Multiline_Input(370,170,200,60,"Description:");
  Fl_Button *lCreate = new Fl_Button(370,350,200,60,"Create");
  dataGroup[4]->hide();
  dataGroup[4]->end();

  // Create Init CB
  tabW->callback(selectGroupCB);

  // Create Back Button
  Fl_Button *backBtn = new Fl_Button(10,430,150,30,"Back");
  // Back Button CB
  backBtn->callback(backBtnCB);
  partMenu->end();
  partMenu->hide();
}

void newWin::backBtnCB(Fl_Widget *w, void *v) {
 ((Fl_Group*)(w->parent()))->hide();
 ((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}

void newWin::showPartMenuCB(Fl_Widget *w, void *v) {
  ((Fl_Group*)(w->parent()->parent()->child(2)))->hide();
  ((Fl_Group*)(w->parent()->parent()->child(3)))->show();
}
