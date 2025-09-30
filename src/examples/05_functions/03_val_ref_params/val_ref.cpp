#include "val_ref.h"

void func_value_param(int num)
{
    num = 20; // This modification won't affect the original argument(variable)
}

void func_ref_param(int &num)
{
    num = 30; // This modification will affect the original argument(variable)
}