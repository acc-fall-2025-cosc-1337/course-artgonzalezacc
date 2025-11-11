#include "ref_pointers.h"

//
void val_ref_ptr_params(int num0, int& num1, int* num2)
{
    num0 = 10; //working with a copy
    num1 = 20; //working with the original memory location of the param
    *num2 = 30;  //working with the original memory location of the param
}

