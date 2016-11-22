#include <iostream>
#include <string>
#include <vector>
#include "shop.h"
using namespace std;

int main() {
  Shop shop;
  shop.create_model();
  cout << "robot 1 10 100" << endl;
  cout << shop.get_robot_name() << " " << shop.get_robot_model_number() << " " << 
   shop.get_robot_price() << " " << shop.get_robot_max_speed() << endl;
}

