#include "void.h"

using std::cout;

void print(int &value)
{
    auto num = 10;
    value = num;

    cout << "Value of num: " << num << "\n";
}