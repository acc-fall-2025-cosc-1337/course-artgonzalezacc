#include<iostream>
#include "switch.h"

int main() 
{
	int option;
	std::cout << "Enter a menu option (1-4): ";
	std::cin >> option;

	std::cout << menu_option(option);
	

	return 0;
}