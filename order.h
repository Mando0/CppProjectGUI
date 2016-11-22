#ifndef order_h
#define order_h 2016
#include<string>
#include"customer.h"
#include"date.h"
#include"status.h"
#include"sale_associate.h"
#include"Robot_Model.h"
using namespace std;


class Order {
public:
    Order(int n, Date d, Status s, Customer c, Sale_Associate sa, Robot_Model m): number(n),date(d), status(s), customer(c), associate(sa), model(m){}

    int get_order_number() {
        return number;
    }
    Date get_order_date() {
        return date;
    }
    Status get_order_status() {
        return status;
    }
    Customer get_customer_order() {
        return customer;
    }
    Sale_Associate get_associate_order() {
        return associate;
    }
    Robot_Model get_model_order() {
        return model;
    }
    
private:
    int number;
    Date date;
    Status status;
    Customer customer;
    Sale_Associate associate;
    Robot_Model model;
};
#endif
