#include<string>
#include "robot_parts.h"
#ifndef head_h
#define head_h 2016
using namespace std;

class Head : public Robot_Parts {
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
};

#endif
