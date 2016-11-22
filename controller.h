#ifndef __CONTROLLER_H
#define __CONTROLLER_H 2016

#include "shop.h"
#include "view.h"

class Controller {
  public:
    Controller (Shop& sho) : shop(sho), view(View(shop)) { }
    void cli();
    void execute_main_menu_cmd(int cmd);
    void execute_create_model_cmd(int cmd);
    void execute_create_parts_cmd(int cmd);
    void execute_show_model(int cmd);
    void execute_pick_model(int cmd);
    void execute_show_report(int cmd);
  private:
    Shop& shop;
    View view;
};

#endif
