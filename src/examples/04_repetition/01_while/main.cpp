#include "while.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	char choice = 'y';

	while(choice == 'y' || choice == 'Y')
	{
		char letter = 'b';

		cout << "Enter a letter: ";
		while (!is_vowel(letter)) 
		{
			cout << letter << " is not a vowel. Please enter a vowel: ";
			cin >> letter;
		}

		cout<< letter << " is a vowel!" << std::endl;
		cout << "Do you want to continue? (y/n): ";
		cin >> choice;
		letter = 'b'; // reset letter to a non-vowel
	}

	return 0;
}