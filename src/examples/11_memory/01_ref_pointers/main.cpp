#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
	int num = 10;
	int& num_ref = num;
	int* num_ptr = &num;//pointer- only works with addresses

	cout<<"Value of num via ref: "<<num_ref<<"\n";
	cout<<"Value of num via pointer: "<<*num_ptr<<"\n";

	
	return 0;
}