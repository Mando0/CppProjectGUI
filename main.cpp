#include "librarys.h"
#include "newWin.h"

int main() {
  // Init Windows
  newWin mainWin(640,480,"Shop");
  
  mainWin.newWinProp();
  mainWin.createLogin();
  mainWin.createPM();

  mainWin.newWinShow();

  return Fl::run();
}
