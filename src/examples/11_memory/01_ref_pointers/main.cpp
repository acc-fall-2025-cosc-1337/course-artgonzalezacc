#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
	int num = 10;
	int& num_ref = num;
	int* num_ptr = &num;//pointer- only works with addresses

	cout<<"Value of num via ref: "<<num_ref<<"\n";
	cout<<"Value of num via pointer: "<<*num_ptr<<"\n\n";
	cout<<"Address of num: "<<&num<<"\n";
	cout<<"Address of num_ref: "<<&num_ref<<"\n";
	cout<<"Address of num_ptr: "<<&num_ptr<<"\n";
	cout<<"Address that num_ptr point to: "<<num_ptr<<"\n";

	//Always use * to work with the value that the pointer points to
	*num_ptr = 20;
	cout<<"Value of num: "<<num<<"\n";
	
	return 0;
}