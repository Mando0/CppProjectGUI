#ifndef locomotor_h
#define locomotor_h 2016
#include<string>
#include "robot_parts.h"
using namespace std;

class Locomotor : public Robot_Parts {
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
    void set_power_consumed(int p){
        power = p;
    }
    double get_max_speed() {
        return max_speed;
    }
    void set_max_speed(double p){
        max_speed = p;
    }

protected:
    double max_speed;
    int power;
};

#endif
