#include <iostream>
#include "void.h"

using std::cout;

int main()
{
    auto num = 0;//x1000

    print(num);//value = print.num   .... value references the address x1000 which is num
    
    cout<<num;
    return 0;
}
    