#include<iostream>
#include "if.h"//to use is_even function here

using std::cout;
using std::cin;
using std::endl;


int main() 
{
	char letter;
	cout << "Enter a letter: ";
	cin >> letter;

	if (is_vowel(letter)) {
		cout << letter << " is a vowel." << endl;
	} else if (is_consonant(letter)) {
		cout << letter << " is a consonant." << endl;
	} else {
		cout << letter << " is not a valid letter." << endl;
	}

	return 0;
}
