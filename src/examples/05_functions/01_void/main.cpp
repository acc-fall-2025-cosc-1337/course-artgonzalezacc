#include <iostream>
#include "void.h"

using std::cout;

int main()
{
    auto num = 0;//x1000

    print(num);//value = print.num   .... value references the address x1000 which is num
    
    cout<<num<<"\n";
    cout<<10*state_tax<<"\n";//constant variable

    return 0;
}
    