#include"date.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    cout<<"Test day"<<endl;
    cout<<"9/8/2016"<<endl;
    Date d(8,9,2016);
    cout<<d.get_month()<<"/"<<d.get_date()<<"/"<<d.get_year()<<endl;
    
}
