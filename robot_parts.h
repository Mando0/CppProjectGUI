#ifndef robot_parts_h
#define robot_parts_h 2016
#include<string>
using namespace std;

class Robot_Parts {
public:
    virtual string get_name() = 0;
    virtual string get_description() = 0;
    virtual int get_part_number() = 0;
    virtual double get_weight () = 0;
    virtual double get_cost () = 0;
    
    void set_name(string n){
        name = n;
    }
    void set_description(string d){
        description = d;
    }
    void set_part_number(int p){
        part_number = p;
    }
    void set_weight(double w){
        weight = w;
    }
    void set_cost(double c){
        cost = c;
    }
protected:
    string name;
    string description;
    int part_number;
    double weight;
    double cost;
};

#endif 
