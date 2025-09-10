#include <iostream>
#include "int.h"

using std::cout;

int main()
{   
    int hours = 40;
    double rate = 15.33;
    double pay = gross_pay(hours, rate);
    cout << "Gross pay: " << pay << "\n";
    return 0;
}