#include "val_ref.h"

void func_value_param(int num)
{
    num = 20; // This modification won't affect the original argument(variable)
}

void func_ref_param(int &num)
{
    num = 30; // This modification will affect the original argument(variable)
}

void func_const_ref_param(const int &num) //const means read-only
{
    //num = 40; // This would cause a compilation error because num is a const reference
    // We can read the value but cannot modify it
    auto temp = num; // This is allowed
    std::cout<<temp<<"\n";
}