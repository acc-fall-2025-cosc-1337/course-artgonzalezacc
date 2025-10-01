#include <iostream>

using std::cout;

int main()
{
    int num = 10; // original value(variable)
    int num1 = 100;
    int &ref = num; // reference variable(ref) to original value(variable) ... via its address

    cout << "Value of num: " << num << "\n"; // 10
    cout << "Value of ref: " << ref << "\n"; // 10

    ref = 20; // modify the value via reference variable(ref)

    cout << "Value of num: " << num << "\n"; // 20
    cout << "Value of ref: " << ref << "\n"; // 20

    ref = num1; // assign the value of num1 to ref (which is a reference to num)

    cout << "Value of num: " << num << "\n"; // 100
    cout << "Value of ref: " << ref << "\n"; // 100

    num1 = 200;

    cout << "Value of num: " << num << "\n"; // ??
    cout << "Value of ref: " << ref << "\n"; // ??

    return 0;
}