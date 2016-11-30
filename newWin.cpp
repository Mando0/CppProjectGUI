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
  robotBtn->callback((Fl_Callback*)createRobotCB);
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
    string a1, desc, name;
    int c, num, comp, totalEng,maxSpd,pwrCons;
    double weight,cost,pow;
    iss >> c >> name;
    switch(c) {
      case 1:
        iss >> num >> weight >> cost >> desc;
        h.set_name(name);
        h.set_part_number(num);
        h.set_weight(weight);
        h.set_cost(cost);
        h.set_description(desc);
        head.push_back(h);
        break;
      case 2:
        iss >> num >> weight >> cost >> pow >> desc; 
        a.set_name(name);
        a.set_part_number(num);
        a.set_weight(weight);
        a.set_cost(cost);
        a.set_power_consumed(pow);
        a.set_description(desc);
        arm.push_back(a);
        break;
      case 3:
        iss >> num >> weight >> cost >> comp >> desc;
        t.set_name(name);
        t.set_part_number(num);
        t.set_weight(weight);
        t.set_cost(cost);
        t.set_compartments(comp);
        t.set_description(desc);
        torso.push_back(t);
        break;
      case 4:
        iss >> num >> weight >> cost >> totalEng >> desc;
        b.set_name(name);
        b.set_part_number(num);
        b.set_weight(weight);
        b.set_cost(cost);
        b.set_energy(totalEng);
        b.set_description(desc);
        battery.push_back(b);
        break;
      case 5:
        iss >> num >> weight >> cost >> maxSpd >> pwrCons >> desc;
        l.set_name(name);
        l.set_part_number(num);
        l.set_weight(weight);
        l.set_cost(cost);
        l.set_max_speed(maxSpd);
        l.set_power_consumed(pwrCons);
        l.set_description(desc);
        l.set_name(name);
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
  

  // Part Details
  //tab3 = new Fl_Hold_Browser(290,40,200,380
  dataGroupS[0] = new Fl_Group(290,40,335,380);
  dataGroupS[0]->box(FL_ENGRAVED_BOX);
  dataGroupS[0]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroupS[0]->labelsize(24);
  hNumS = new Fl_Int_Input(390,50,220,20,"Part Number:");
  hWeightS = new Fl_Float_Input(390,70,220,20,"Part Weight:");
  hCostS = new Fl_Float_Input(390,90,220,20,"Part Cost:");
  hDescS = new Fl_Multiline_Input(390,110,220,60,"Description:");
  dataGroupS[0]->end();

  dataGroupS[1] = new Fl_Group(290,40,335,380);
  dataGroupS[1]->box(FL_ENGRAVED_BOX);
  dataGroupS[1]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroupS[1]->labelsize(24);
  aNumS = new Fl_Int_Input(390,50,220,20,"Part Number:");
  aWeightS = new Fl_Float_Input(390,70,220,20,"Part Weight:");
  aCostS = new Fl_Float_Input(390,90,220,20,"Part Cost:");
  aPowS = new Fl_Float_Input(390,110,220,20,"Part Power:");
  aDescS = new Fl_Multiline_Input(390,130,220,60,"Description:");
  dataGroupS[1]->hide();
  dataGroupS[1]->end();

  dataGroupS[2] = new Fl_Group(290,40,335,380);
  dataGroupS[2]->box(FL_ENGRAVED_BOX);
  dataGroupS[2]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroupS[2]->labelsize(24);
  tNumS = new Fl_Int_Input(390,50,220,20,"Part Number:");
  tWeightS = new Fl_Float_Input(390,70,220,20,"Part Weight:");
  tCostS = new Fl_Float_Input(390,90,220,20,"Part Cost:");
  tBatCompS = new Fl_Int_Input(390,110,220,20,"Compartments:");
  tDescS = new Fl_Multiline_Input(390,130,220,60,"Description:");
  dataGroupS[2]->hide();
  dataGroupS[2]->end();

  dataGroupS[3] = new Fl_Group(290,40,335,380);
  dataGroupS[3]->box(FL_ENGRAVED_BOX);
  dataGroupS[3]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroupS[3]->labelsize(24);
  bNumS = new Fl_Int_Input(390,50,220,20,"Part Number:");
  bWeightS = new Fl_Float_Input(390,70,220,20,"Part Weight:");
  bCostS = new Fl_Float_Input(390,90,220,20,"Part Cost:");
  bTotalEngS = new Fl_Int_Input(390,110,220,20,"Total Energy:");
  bDescS = new Fl_Multiline_Input(390,130,220,60,"Description:");
  dataGroupS[3]->hide();
  dataGroupS[3]->end();

  dataGroupS[4] = new Fl_Group(290,40,335,380);
  dataGroupS[4]->box(FL_ENGRAVED_BOX);
  dataGroupS[4]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
  dataGroupS[4]->labelsize(24);
  lNumS = new Fl_Int_Input(390,50,220,20,"Part Number:");
  lWeightS = new Fl_Float_Input(390,70,220,20,"Part Weight:");
  lCostS = new Fl_Float_Input(390,90,220,20,"Part Cost:");
  lMaxSpdS = new Fl_Int_Input(390,110,220,20,"Total Energy:");
  lPwrConsS = new Fl_Int_Input(390,130,220,20,"Power Consumed:");
  lDescS = new Fl_Multiline_Input(390,150,220,60,"Description:");
  dataGroupS[4]->hide();
  dataGroupS[4]->end();

  tab1->callback(selectPartCB,this);
  tab2->callback(pickPartCB,this);

  // Back Button
  Fl_Button *backBtn = new Fl_Button(10,430,150,30,"Back");
  backBtn->callback(backBtnCB);
  partMenu->end();
  partMenu->hide();
}


void newWin::pickPartCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->pickPart(w);
}

void newWin::pickPart(Fl_Widget *w) {
  int i = tab1->value();
  int j = tab2->value();
  switch(i) {
    case 1:
      if( j == 0) {
        hNumS->value("");
        hWeightS->value("");
        hCostS->value("");
        hDescS->value("");
        break;
      } 
      hNumS->value(to_string(head[j-1].get_part_number()).c_str());
      hWeightS->value(to_string(head[j-1].get_weight()).c_str());
      hCostS->value(to_string(head[j-1].get_cost()).c_str());
      hDescS->value(head[j-1].get_description().c_str());
      break;
    case 2:
      if(j == 0) {
        aNumS->value("");
        aWeightS->value("");
        aCostS->value("");
        aPowS->value("");
        aDescS->value("");
        break;
      }
      aNumS->value(to_string(arm[j-1].get_part_number()).c_str());
      aWeightS->value(to_string(arm[j-1].get_weight()).c_str());
      aCostS->value(to_string(arm[j-1].get_cost()).c_str());
      aPowS->value(to_string(arm[j-1].power_consumed()).c_str());
      aDescS->value(arm[j-1].get_description().c_str());
      break;
    case 3:
      if(j == 0) {
        tNumS->value("");
        tWeightS->value("");
        tCostS->value("");
        tBatCompS->value("");
        tDescS->value("");
        break;
      }
      tNumS->value(to_string(torso[j-1].get_part_number()).c_str());
      tWeightS->value(to_string(torso[j-1].get_weight()).c_str());
      tCostS->value(to_string(torso[j-1].get_cost()).c_str());
      tBatCompS->value(to_string(torso[j-1].get_compartments()).c_str());
      tDescS->value(torso[j-1].get_description().c_str());
      break;
    case 4:
     if(j == 0) {
        bNumS->value("");
        bWeightS->value("");
        bCostS->value("");
        bTotalEngS->value("");
        bDescS->value("");
        break;
      }
      bNumS->value(to_string(battery[j-1].get_part_number()).c_str());
      bWeightS->value(to_string(battery[j-1].get_weight()).c_str());
      bCostS->value(to_string(battery[j-1].get_cost()).c_str());
      bTotalEngS->value(to_string(battery[j-1].get_energy()).c_str());
      bDescS->value(torso[j-1].get_description().c_str());
      break;  
    case 5:
     if(j == 0) {
        lNumS->value("");
        lWeightS->value("");
        lCostS->value("");
        lMaxSpdS->value("");
        lPwrConsS->value("");
        lDescS->value("");
        break;
      }
      lNumS->value(to_string(locomotor[j-1].get_part_number()).c_str());
      lWeightS->value(to_string(locomotor[j-1].get_weight()).c_str());
      lCostS->value(to_string(locomotor[j-1].get_cost()).c_str());
      lMaxSpdS->value(to_string(locomotor[j-1].get_max_speed()).c_str());
      lPwrConsS->value(to_string(locomotor[j-1].power_consumed()).c_str());
      lDescS->value(locomotor[j-1].get_description().c_str());
      break;  
  }
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
  for(int i = 0; i < 5; i++) {
    if( i == (tab1->value()-1)){
      dataGroupS[i]->show();
    }
    else {
      dataGroupS[i]->hide();
    }
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
  partsinfo << aName->value() << " ";
  partsinfo << aNum->value() << " ";
  partsinfo << aWeight->value() << " ";
  partsinfo << aCost->value() << " ";
  partsinfo << aPow->value() << " ";
  partsinfo << aDesc->value() << " ";
  partsinfo << '\n';
  partsinfo.close();
  aName->value("");
  aNum->value("");
  aWeight->value("");
  aCost->value("");
  aPow->value("");
  aDesc->value("");
}

void newWin::saveTorsoCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->saveTorso(w);
}

void newWin::saveTorso(Fl_Widget *w) {
  ofstream partsinfo("info.txt",ios_base::out|ios_base::app);
  partsinfo << "3 ";
  partsinfo << tName->value() << " ";
  partsinfo << tNum->value() << " ";
  partsinfo << tWeight->value() << " ";
  partsinfo << tCost->value() << " ";
  partsinfo << tBatComp->value() << " ";
  partsinfo << tDesc->value() << " ";
  partsinfo << '\n';
  partsinfo.close();
  tName->value("");
  tNum->value("");
  tWeight->value("");
  tCost->value("");
  tBatComp->value("");
  tDesc->value("");
}

void newWin::saveBatteryCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->saveBattery(w);
}

void newWin::saveBattery(Fl_Widget *w) {
  ofstream partsinfo("info.txt",ios_base::out|ios_base::app);
  partsinfo << "4 ";
  partsinfo << bName->value() << " ";
  partsinfo << bNum->value() << " ";
  partsinfo << bWeight->value() << " ";
  partsinfo << bCost->value() << " ";
  partsinfo << bTotalEng->value() << " ";
  partsinfo << bDesc->value() << " ";
  partsinfo << '\n';
  partsinfo.close();
  bName->value("");
  bNum->value("");
  bWeight->value("");
  bCost->value("");
  bTotalEng->value("");
  bDesc->value("");
}

void newWin::saveLocomotorCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->saveLocomotor(w);
}

void newWin::saveLocomotor(Fl_Widget *w) {
  ofstream partsinfo("info.txt",ios_base::out|ios_base::app);
  partsinfo << "5 ";
  partsinfo << lName->value() << " ";
  partsinfo << lNum->value() << " ";
  partsinfo << lWeight->value() << " ";
  partsinfo << lCost->value() << " ";
  partsinfo << lMaxSpd->value() << " ";
  partsinfo << lPwrCons->value() << " ";
  partsinfo << lDesc->value() << " ";
  partsinfo << '\n';
  partsinfo.close();
  lName->value("");
  lNum->value("");
  lWeight->value("");
  lCost->value("");
  lMaxSpd->value("");
  lPwrCons->value("");
  lDesc->value("");
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
  bCreate->callback(saveBatteryCB,this);
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
  lCreate->callback(saveLocomotorCB,this);
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

void newWin::createRobotCB(Fl_Widget *w, void *v) {
  ((Fl_Group*)(w->parent()->parent()->child(2)))->hide();
  ((Fl_Group*)(w->parent()->parent()->child(5)))->show();
}

/*void newWin::addHCostCB(Fl_Widget *w, void *v) {
  ((newWin*)v)->addHCost(w);
}

void newWin::addHCost(Fl_Widget *w) {
  int i = hTab->value()-1;
  if(i == -1) return;
  rPartCost->value(to_string(head[i].get_cost()).c_str());
}
*/
void newWin::createRobotWin() {
  createRobotG = new Fl_Group(0,30,640,480);
  createRobotG->begin();
  if( head.empty() || arm.empty() || battery.empty() || locomotor.empty() || torso.empty()) {
    Fl_Box *title = new Fl_Box(50,50,540,30);
    title->label("Need to create one of each part to make model");
    title->labelsize(20);
  }
  else {
    hTab = new Fl_Hold_Browser(10,40,110,200);
    for(int i = 0; i < head.size(); i++) {
      hTab->add(head[i].get_name().c_str());
    }
    aTab = new Fl_Hold_Browser(130,40,110,200);
    for(int i = 0; i < arm.size(); i++) {
      aTab->add(arm[i].get_name().c_str());
    }
    tTab = new Fl_Hold_Browser(250,40,110,200);
    for(int i = 0; i < torso.size(); i++) {
      tTab->add(torso[i].get_name().c_str());
    } 
    bTab = new Fl_Hold_Browser(370,40,110,200);
    for(int i = 0; i < battery.size(); i++) {
      bTab->add(battery[i].get_name().c_str());
    }
    lTab = new Fl_Hold_Browser(490,40,110,200);
    for(int i = 0; i < locomotor.size(); i++) {
      lTab->add(locomotor[i].get_name().c_str());
    } 
    robotBox = new Fl_Group(10,250,590,160);
    robotBox->box(FL_ENGRAVED_BOX);
    rName = new Fl_Input(110,260,200,20,"Robot Name:");
    rCost = new Fl_Float_Input(110,280,200,20,"Robot Cost:");
    rNum = new Fl_Int_Input(110,300,200,20,"Model number:");
    rMaxSpd = new Fl_Int_Input(110,320,200,20,"Max Speed:");
    rPartCost = new Fl_Float_Input(410,260,200,20,"Part Cost:");
    //hTab->callback(addHCostCB);
    Fl_Button *rCreate = new Fl_Button(410,430,150,30,"Create");
    robotBox->end();


  }

  // Back Btn
  Fl_Button *backBtn = new Fl_Button(10,430,150,30,"Back");
  backBtn->callback(backBtnCB);

  createRobotG->end();
  createRobotG->hide();
}






