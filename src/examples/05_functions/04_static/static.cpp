#include "static.h"

using std::cout;

void use_local_variable()
{
    auto num = 10;
    cout<<"local var: "<<num<<"\n";

    num+= 1;

    cout<<"local var: "<<num<<"\n";
}