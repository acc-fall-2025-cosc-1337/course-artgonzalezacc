#include<iostream>
#include<memory>

using std::cout;
using std::shared_ptr; using std::make_shared;

int main() 
{
	shared_ptr<int> num = make_shared<int>(150);//creates dynamic memory on the heap
	cout<<*num<<"\n";//use
	cout<<"Shared count: "<<num.use_count()<<"\n";

	shared_ptr<int> num1 = num;
	cout<<*num<<"\n";//use
	cout<<"Shared count: "<<num.use_count()<<"\n";

	//unique ptr calls delete for us(right before main is removed from memory)
	return 0;
}