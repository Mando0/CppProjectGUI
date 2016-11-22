#include <stdio.h>
#include<iostream>
#include "status.h"
using namespace std;

int main() {
    cout<<"Test status"<<endl;
    cout<<"0"<<endl;
    Status s(false);
    cout<<s.get_status()<<endl;
}
