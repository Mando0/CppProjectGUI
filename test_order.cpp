#include <stdio.h>
#include <iostream>
#include "order.h"
using namespace std;

int main() {
    cout << "Test Order" <<endl;
    cout << "Order:1" <<endl;
    cout << "Date:10/11/2016 "<<endl;
    cout << "Customer: Mary Lamb "<<endl;
    cout << "Customer Number: 215 "<<endl;
    cout << "Customer Balance: 100 "<<endl;
    cout << "Sale Associate: Micheal Perry "<<endl;
    cout << "Number: 567 "<<endl;
    cout << "Status: 1 "<<endl;
    cout << "Model: Robt 001 10 100"<<endl;
    
    Customer c ("Mary Lamb",215,100.00);
    Sale_Associate sa("Michael Perry", 567);
    Date d(11,10,2016);
    Status s(true);
    Robot_Model robot("robot", 001, 10.00, 100.00);
    Order o(1,d,s,c,sa,robot);
    cout<< "Order: " << o.get_order_number()<<endl;
    cout<< "Date: " << o.get_order_date().get_month()<<"/"<<o.get_order_date().get_date()<<"/"<<o.get_order_date().get_year()<<endl;
    cout<< "Customer: " << o.get_customer_order().get_customer_name()<<endl;
    cout<< "Customer Number: " << o.get_customer_order().get_customer_phone()<<endl;
    cout<< "Customer Balance: " << o.get_customer_order().get_customer_bill()<<endl;
    cout<< "Sale Associate: " << o.get_associate_order().get_employee_name()<<endl;
    cout<< "Number: " << o.get_associate_order().get_employee_phone()<<endl;
    cout<< "Status: " << o.get_order_status().get_status()<<endl;
    cout<< "Model: " << o.get_model_order().get_name() << " " << o.get_model_order().get_model_number() << " " << o.get_model_order().get_price() << " " << o.get_model_order().get_max_speed() << endl;
}
