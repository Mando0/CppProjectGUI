#include <iostream>
#include <string>
#include "battery.h"

using namespace std;

int main() {
    cout << "Test Battery Component" << endl;
    cout << "Battery first battery 1 4 2 20" << endl;
    Battery b;
    b.set_name("Battery");
    b.set_description("first battery");
    b.set_part_number(1);
    b.set_weight(4.0);
    b.set_cost(2);
    b.set_energy(20);

    cout << b.get_name() << " " << b.get_description() << " " << b.get_part_number()
    << " " << b.get_weight() << " " << b.get_cost() << " " << b.get_energy()
    << " " << endl;
}
