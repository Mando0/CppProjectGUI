#ifndef sale_associate_h
#define sale_associate_h 2016
#include<string>
#include"order.h"
using namespace std;

class Sale_Associate {
public:
    Sale_Associate(string ename, int ephone):name(ename),number(ephone){}

    string get_employee_name() {
        return name;
    }

    int get_employee_phone() {
        return number;
    }
    
private:
    string name;
    int number;
};
#endif
