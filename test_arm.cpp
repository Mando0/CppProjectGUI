#include <iostream>
#include <string>
#include "arm.h"
using namespace std;

int main() {
    
    cout << "Test Arm Component"<<endl;
    cout << "Arm first arm 1 4 2 20" <<endl;
    Arm a;
    a.set_name("Arm");
    a.set_description("first arm");
    a.set_part_number(1);
    a.set_weight(4.0);
    a.set_cost(2);
    a.set_power_consumed(20);
    cout << a.get_name() << " "<< a.get_description()<< " " << a.get_part_number() << " " << a.get_weight() << " " << a.get_cost() << " " << a.power_consumed()<< endl;
}
