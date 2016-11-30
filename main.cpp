#include "librarys.h"
#include "newWin.h"
#include "shop.h"

int main() {
  // Init Windows
  newWin mainWin(640,480,"Robbie Robot Shop");
  
  mainWin.newWinProp();
  // child 1
  mainWin.createLogin();
  // child 2
  mainWin.createPM();
  // child 3
  mainWin.createPartMenu();
  // child 4
  mainWin.partView();
  // child 5
  mainWin.createRobotWin();

  mainWin.newWinShow();

  return Fl::run();
}
