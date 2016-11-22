#ifndef __BATTERY_H
#define __BATTERY_H 2016
#include <iostream>
#include <string>
#include "robot_parts.h"

using namespace std;

class Battery : public Robot_Parts{
  public:
    string get_name(){
        return name;
    }
    string get_description(){
        return description;
    }
    int get_part_number(){
        return part_number;
    }
    double get_weight(){
        return weight;
    }
    double get_cost(){
        return cost;
    }
    double get_energy() {
      return energy;
    }
    void set_energy(double e) {
        energy = e;
    }
    
  protected:
    double energy;
};

#endif
