#include<iostream>
#include<memory>

using std::cout;
using std::shared_ptr; using std::make_shared;
using std::weak_ptr;

int main() 
{
	shared_ptr<int> num = make_shared<int>(150);//creates dynamic memory on the heap
	cout<<*num<<"\n";//use
	cout<<"count: "<<num.use_count()<<"\n";
	
	weak_ptr<int> wp_num = num;
	cout<<"count: "<<num.use_count()<<"\n";

	if(!wp_num.expired())
	{
		shared_ptr<int> sp1 = wp_num.lock();
		cout<<*sp1<<"\n";
	}

	//unique ptr calls delete for us(right before main is removed from memory)
	return 0;
}