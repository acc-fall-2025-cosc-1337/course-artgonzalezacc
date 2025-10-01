#include "void.h"

using std::cout;

void print(int &value)
{
    auto num = 10;
    value = num * state_tax; // modify the argument passed by reference

    cout << "Value of num: " << value << "\n";
}