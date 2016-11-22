#include <iostream>
#include <string>
#include "view.h"
using namespace std;

void View::show_menu() {
  cout << "Main Menu   " << endl;
  cout << "------------" << endl;
  cout << "1 Create    " << endl;
  cout << "2 Report    " << endl;
  cout << "0 Quit      " << endl;
  cout << endl << endl;
}

void View::show_report() {
  cout << "Report           " << endl;
  cout << "-------------------" << endl;
  cout << "1 Orders           " << endl;
  cout << "2 Customers        " << endl;
  cout << "3 Sales Associate  " << endl;
  cout << "4 Models           " << endl;
  cout << "0 Quit to Main Menu" << endl;
}

void View::show_create() {
  cout << "Create             " << endl;
  cout << "-------------------" << endl;
  cout << "1 Robot Model      " << endl;
  cout << "2 Create Parts     " << endl;
  cout << "3 Order            " << endl;
  cout << "4 Customer         " << endl;
  cout << "5 Sales Associate  " << endl;
  cout << "0 Quit to Main Menu" << endl;
  cout << endl << endl;
}

void View::show_robot_model() {
  cout << "Robot Model        " << endl;
  cout << "-------------------" << endl;
  cout << "Name is: " << shop.get_robot_name() << endl;
  cout << endl;
}

void View::create_parts_menu() {
  cout << "Which part to create?: " << endl;
  cout << "1 Head                 " << endl;
  cout << "2 Arm                  " << endl;
  cout << "3 Torso                " << endl;
  cout << "4 Battery              " << endl;
  cout << "5 Locomotor            " << endl;
  cout << endl;
}

void View::part_list() {
  shop.get_head_vector();
}

void View::show_model() {
  cout << "Available Models: " << endl;
  for(int i = 0; i < shop.robot_model.size(); i++) {
    cout << i << ") " << shop.robot_model[i].get_name() << endl;
  }
  cout << "0) Quit" << endl;
}
