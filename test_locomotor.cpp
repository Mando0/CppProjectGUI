#include <iostream>
#include <string>
#include "locomotor.h"
using namespace std;


int main() {
    
    cout << "Test Locomotor Component"<<endl;
    cout << "locomotor first locomotor 1 6 12 30 50" <<endl;
    Locomotor l;
    l.set_name("locomotor");
    l.set_description("first locomotor");
    l.set_part_number(1);
    l.set_weight(6);
    l.set_cost(12);
    l.set_power_consumed(30);
    l.set_max_speed(50);
    cout << l.get_name() << " "<< l.get_description()<< " " << l.get_part_number() << " " << l.get_weight() << " " << l.get_cost() << " " << l.power_consumed() << " " << l.get_max_speed()<< endl;
 
 }
