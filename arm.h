#ifndef arm_h
#define arm_h 2016
#include<string>
#include "robot_parts.h"
using namespace std;

class Arm : public Robot_Parts {
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
    int power_consumed(){
        return power;
    }
    void set_power_consumed(int s){
        power = s;
    }
                                                                                                                   
protected:
    int power;
};


#endif
