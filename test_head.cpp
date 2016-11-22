#include <iostream>
#include <string>
#include "head.h"
using namespace std;

int main() {
    cout << "Test Head Component"<<endl;
    cout << "head first head 1 0.5 4"<<endl;
    Head h;
    h.set_name("head");
    h.set_description("first head");
    h.set_part_number(1);
    h.set_weight(0.5);
    h.set_cost(4.0);
    cout << h.get_name() << " " << h.get_description()<< " " << h.get_part_number() << " " << h.get_weight() << " " << h.get_cost() << endl;
    
}

