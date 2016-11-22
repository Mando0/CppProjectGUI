#include <stdio.h>
#include <iostream>
#include "sale_associate.h"
#include <string>
using namespace std;

int main() {
    cout << "Test Sale Associate" << endl;
    cout << "Michael Perry 567" <<endl;
    Sale_Associate s("Michael Perry", 567);
    cout<< s.get_employee_name() << " " << s.get_employee_phone()<<endl;
}
