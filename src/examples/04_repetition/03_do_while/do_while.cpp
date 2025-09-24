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

void display_menu() 
{
    cout << "Menu Options:" << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "4. Exit" << endl;
    cout << "Please select an option (1-4): ";
}

//Write code for void function run_menu to display a menu
//with 3 options and prompt user to select an option.
void run_menu() 
{
    int option;
    do {
        display_menu();        
        cin >> option;
        handle_option(option);
        
    } while (option != 4);
   
}

void handle_option(int option) 
{
    switch (option) 
    {
        case 1:
            do_something();
            break;
        case 2:
            cout << "Handling Option 2" << endl;
            break;
        case 3:
            cout << "Handling Option 3" << endl;
            break;
        case 4:
            cout << "Exiting menu." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
    }
}


void do_something()
{
    cout << "Doing something..." << endl;
}
