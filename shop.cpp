#include "shop.h"
#include "Robot_Model.h"
#include "head.h"
#include "arm.h"
#include <iostream>
#include <string>
#include <vector>

void Shop::create_model() {
  if( head.empty()) {
    cout << "Need to create head part" << endl;
  }
  Robot_Model model;
  model.set_head(head[0]);
  model.set_arm(arm[0]);
  robot_model.push_back(model);
} 
