#include "GUI.H"
#include "Points.h"
#include "Windows.h"

int main() {
  Windows *main_window = new Windows(0,0,640,480,"Robot Shop");
  Fl::run();
  delete main_window;
  return 1;
}
