#include "do_while.h"

using std::cout;
using std::cin;
using std::endl;

//Write code for void function prompt_user to loop until
//user opts not to continue. 
void prompt_user() {
    char choice;
    do 
    {
        cout << "Hello, User!" << std::endl;
        cout << "Would you like to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
} 



