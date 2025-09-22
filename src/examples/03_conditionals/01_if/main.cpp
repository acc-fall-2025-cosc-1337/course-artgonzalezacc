#include<iostream>

using std::cout;
using std::cin;
using std::endl;


int main() 
{
	int num = 1;
	
	if(num > 0)
	{
		int num = 10; //local variable to if block
		cout<<"num: "<<num<<endl;
		num  = num + 10;
	}

	cout<<"num: "<<num<<endl;
	
	return 0;
}
