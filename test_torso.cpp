#include <iostream>
#include <string>
#include <vector>
#include "torso.h"
#include "head.h"
using namespace std;

int main() {
    
    cout << "Test Torso Component"<<endl;
    cout << "Torso first torso 1 2 3 2 Head first head 2 3 4" <<endl;
    cout << "locomotor first locomotor 1 6 12 30 50" << endl;
    cout << "Arm first arm  1 4 2 20" <<endl;
    cout << "Battery first battery 1 4 2 20" <<endl;
    
    Torso t;
    t.set_name("Torso");
    t.set_description("first torso");
    t.set_part_number(1);
    t.set_weight(2.0);
    t.set_cost(3);
    t.set_compartments(2);
    
    Head h ;/*= t.get_torso_head() ;*/
    h.set_name("Head");
    h.set_description("first head");
    h.set_part_number(2);
    h.set_weight(3.0);
    h.set_cost(4.0);
    
    Locomotor l = t.get_torso_locomotor();
    l.set_name("locomotor");
    l.set_description("first locomotor");
    l.set_part_number(1);
    l.set_weight(6);
    l.set_cost(12);
    l.set_power_consumed(30);
    l.set_max_speed(50);
    
    Arm a;
    a.set_name("Arm");
    a.set_description("first arm");
    a.set_part_number(1);
    a.set_weight(4.0);
    a.set_cost(2);
    a.set_power_consumed(20);
    
    t.set_torso_arm(a);
    
    Arm c = t.get_torso_arm(0);
    
    Battery b1;
    b1.set_name("Battery");
    b1.set_description("first battery");
    b1.set_part_number(1);
    b1.set_weight(4.0);
    b1.set_cost(2);
    b1.set_energy(20);
    
    t.set_torso_battery(b1);
    Battery b2 = t.get_torso_battery(0);
    
    cout << t.get_name() << " "<< t.get_description()<< " " << t.get_part_number() << " " << t.get_weight() << " " << t.get_cost() << " " << t.get_compartments() << " " <<endl;
    /* h.get_name() << " " << h.get_description() << " " << h.get_part_number() << " " << h.get_weight() << " " << h.get_cost() << endl;*/
    cout << &h;
    
    cout << l.get_name() << " "<< l.get_description()<< " " << l.get_part_number() << " " << l.get_weight() << " " << l.get_cost() << " " << l.power_consumed() << " " << l.get_max_speed()<< endl;
    
   cout << c.get_name() << " "<< c.get_description()<< " " << c.get_part_number() << " " << c.get_weight() << " " << c.get_cost() << " " << c.power_consumed()<< endl;
    
    cout << b2.get_name() << " "<< b2.get_description()<< " " << b2.get_part_number() << " " << b2.get_weight() << " " << b2.get_cost() << " " << b2.get_energy()<< endl;
    
    
    
    
}
