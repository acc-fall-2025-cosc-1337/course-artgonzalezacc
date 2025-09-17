#include<iostream>

using std::cout;
using std::cin;
using std::endl;


int main() 
{
	//curly braces are optional for single statement blocks
	//but it is a good practice to always use them
	//this helps to avoid bugs when adding statements later
	//and improves readability
	if(true)
	{
		cout << "Condition is true" << endl;
		cout << "Condition ???" << endl;
	}


	return 0;
}
