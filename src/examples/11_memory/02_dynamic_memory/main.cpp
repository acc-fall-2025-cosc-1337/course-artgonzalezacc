#include<iostream>
#include<memory>

using std::cout;
using std::unique_ptr; using std::make_unique;

int main() 
{
	unique_ptr<int> num = make_unique<int>(150);//creates dynamic memory on the heap
	cout<<*num<<"\n";//use

	//unique ptr calls delete for us(right before main is removed from memory)
	return 0;
}