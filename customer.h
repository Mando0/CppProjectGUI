#ifndef customer_h
#define customer_h 2016
#include<string>
using namespace std;

class Customer {
public:
    Customer(string cname, int cphone, double cbill){
        name = cname;
        phone = cphone;
        bill = cbill;
    }

    string get_customer_name() {
        return name;
    }
    int get_customer_phone() {
        return phone;
    }
    
    double get_customer_bill() {
        return bill;
    }

private:
    string name;
    int phone;
    double bill;
    
};

#endif 
