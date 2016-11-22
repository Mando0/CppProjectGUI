#include "librarys.h"
#include "newWin.h"

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

  mainWin.newWinShow();

  return Fl::run();
}
