#include<iostream>
#include "switch.h"

int main() 
{
	int option;
	menu_options();
	std::cin >> option;

	std::cout << menu_option(option);
	

	return 0;
}