#include "controller.h"
#include "view.h"
#include "shop.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Controller::cli() {
  int cmd = -1;
  while( cmd != 0 ) {
    view.show_menu();
    cout << "Command? :";
    cin >> cmd;
    cin.ignore(); 
    execute_main_menu_cmd(cmd);
  }
}

void Controller::execute_main_menu_cmd(int cmd) {
  if (cmd == 1) {
    while(cmd != 0) {
      view.show_create();
      cout << "Command? :";
      cin >> cmd;
      cin.ignore();
      execute_create_model_cmd(cmd);
    }
  }
  // List of Models
  else if(cmd == 2) {
    while(cmd != 0 ) {
      view.show_report();
      cout << "Command?: ";
      cin >> cmd;
      cin.ignore();
      execute_show_report(cmd);
    }
  }
}

void Controller::execute_show_report(int cmd) {
  if(cmd == 4) {
    view.show_model();
    cout << "Command?: ";
    cin >> cmd;
    cin.ignore();
    execute_show_model(cmd);
  }
}

void Controller::execute_create_model_cmd(int cmd) {
  // Command to create robot
  if( cmd == 1) {
    shop.create_model();
  }
  // Command to create parts
  else if( cmd == 2) {
    view.create_parts_menu();
    cout << "Command? : ";
    cin >> cmd;
    cin.ignore();
    execute_create_parts_cmd(cmd);
  }
  else if(cmd == 3) {
    view.show_model();
    cout << "Which one to order?: ";
    cin >> cmd;
    cin.ignore();
    execute_pick_model(cmd);
  }
}

void Controller::execute_create_parts_cmd(int cmd) {
  if(cmd == 1) {
    shop.create_head();
  }
  else if(cmd == 2) {
    shop.create_arm();
  }
  else if(cmd == 3) {
    shop.create_torso();
  }
  else if(cmd == 4) {
    shop.create_battery();
  }
  else if(cmd == 5) {
    shop.create_locomotor();
  }
}

void Controller::execute_show_model(int cmd) {
  cout << "The Head part is: " << shop.robot_model[cmd].get_head() << endl;
  cout << "The Arm part is: " << shop.robot_model[cmd].get_arm() << endl;
  cout << "The Battery part is: " << shop.robot_model[cmd].get_battery() << endl;
  cout << "The Locomotor part is: " << shop.robot_model[cmd].get_locomotor() << endl;
  cout << "The Torso part is: " << shop.robot_model[cmd].get_torso() << endl;
}

void Controller::execute_pick_model(int cmd) {
  int quantity;
  cout << "How many do you want of " << shop.robot_model[cmd].get_name() << " ?: " << endl;
  cin >> quantity;
  shop.set_quantity(quantity);
  execute_show_model(cmd);
  cout << "Total price is: " << shop.robot_model[cmd].get_price() * quantity << endl;
}







