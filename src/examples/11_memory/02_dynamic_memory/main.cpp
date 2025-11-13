#include<iostream>

using std::cout;

int main() 
{
	int* num = new int(10);//create dynamic memory(grap a memory address/block from the heap)
	cout<<*num<<"\n";//for how long do i need the dynamic memory
	delete num;

	return 0;
}