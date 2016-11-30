#include "librarys.h"

class newWin {
  public:
    newWin(int x, int y, const char* l) : x(x), y(y), label(l) {}
    void newWinProp();
    void newWinShow();
    void createLogin();
    void createPM();
    void createPartMenu();
    void partView();
    void createRobotWin();
    void selectPart(Fl_Widget *w);
    void saveTorso(Fl_Widget *w);
    void saveHead(Fl_Widget *w);
    void saveArm(Fl_Widget *w);
    void saveBattery(Fl_Widget *w);
    void saveLocomotor(Fl_Widget *w);
    void pickPart(Fl_Widget *w);
    void createRobot(Fl_Widget *w);
    void addHCost(Fl_Widget *w);
    static void loginBtnCB(Fl_Widget *w,void *v);
    static void showPartMenuCB(Fl_Widget *w, void *v);
    static void selectGroupCB(Fl_Widget *w, void *v);
    static void saveHeadCB(Fl_Widget *w, void *v);
    static void backBtnCB(Fl_Widget *w, void *v);
    static void logoutBtnCB(Fl_Widget *w, void *v);
    static void partViewCB(Fl_Widget *w, void*);
    static void saveArmCB(Fl_Widget *w, void*);
    static void selectPartCB(Fl_Widget *w, void*);
    static void saveTorsoCB(Fl_Widget *w, void* v);
    static void saveBatteryCB(Fl_Widget *w, void *v);
    static void saveLocomotorCB(Fl_Widget *w, void *v);
    static void pickPartCB(Fl_Widget *w, void *v);
    static void createRobotCB(Fl_Widget *w, void *v);
    static void addHCostCB(Fl_Widget *w, void *v);
  private:
    int x,y;
    const char* label;
    Fl_Window *win;
    Fl_Menu_Bar *menuBar;
    Fl_Group *login, *pm, *partMenu, *dataGroup[5] = {0,0,0,0,0}, *dataGroupS[5] = {0,0,0,0,0};
    Fl_Group *createRobotG, *robotBox;
    Fl_Hold_Browser *tabW, *tab2, *tab1;
    Fl_Hold_Browser *hTab, *aTab, *bTab, *lTab, *tTab;
    Fl_Input *hName, *aName, *lName, *bName, *tName, *rName;
    Fl_Int_Input *hNumS, *aNumS, *tNumS, *tBatCompS, *bNumS, *bTotalEngS, *lNumS, *lMaxSpdS, *lPwrConsS;
    Fl_Int_Input *hNum, *aNum, *lNum, *tBatComp, *bNum, *bTotalEng, *tNum, *lMaxSpd, *lPwrCons;
    Fl_Int_Input *rNum, *rMaxSpd;
    Fl_Float_Input *hWeight, *hCost, *aWeight, *aCost, *aPow, *lWeight, *lCost, *bWeight, *bCost, *tCost,*tWeight;
    Fl_Float_Input *hWeightS, *hCostS, *aWeightS, *aCostS, *aPowS, *tWeightS, *tCostS;
    Fl_Float_Input *bWeightS, *bCostS, *lWeightS, *lCostS, *rCost, *rPartCost;
    Fl_Multiline_Input *hDesc, *hDescS, *aDesc, *aDescS, *lDesc, *bDesc, *tDesc, *tDescS, *bDescS, *lDescS;
    vector<Head> head;
    vector<Arm> arm;
    vector<Torso> torso;
    vector<Battery> battery;
    vector<Locomotor> locomotor;
    Head h;
    Arm a;
    Torso t;
    Battery b;
    Locomotor l;
};








