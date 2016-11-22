#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
using namespace std;

int main() {
    cout << "Test Customer" <<endl;
    cout << "Mary Lamb 215 100"<<endl;
    Customer c ("Mary Lamb",215,100.00);
    cout << c.get_customer_name()<< " " << c.get_customer_phone() << " " << c.get_customer_bill() <<endl;
   
    
}
