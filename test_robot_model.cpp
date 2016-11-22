#include "Robot_Model.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Robot_Model robot("robot", 001, 10.00, 100.00);
  cout << "robot 001 10.00 100.00" << endl;
  cout << robot.get_name() << " " << robot.get_model_number() << " " << robot.get_price() << " " 
    << robot.get_max_speed() << endl;
}
