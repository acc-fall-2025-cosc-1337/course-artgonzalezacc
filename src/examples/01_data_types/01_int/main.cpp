#include <iostream>
#include "int.h"

using std::cout;

int main()
{   
    int result;//declare
    result = add_numbers(5, 7);
    cout << "The sum is: " << result << "\n";

    result = 50;
    cout << "The sum is: " << result << "\n";

    return 0;
}