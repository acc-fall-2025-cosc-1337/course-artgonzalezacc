//atm.cpp
#include "atm.h"

using std::cin;
using std::cout;

ATM::ATM(std::vector<BankAccount*>& a) 
: accounts(a) 
{
    account_index = 0;
}

void ATM::display_balance()
{
    BankAccount* account = accounts[account_index];
    cout<<"Balance: "<<account->get_balance();
}

void ATM::make_deposit()
{
    auto amount = 0;
    cout<<"Enter deposit amount: ";
    cin>>amount;

    BankAccount* account = accounts[account_index];
    account->deposit(amount);
}

void ATM::make_withdraw()
{
    auto amount = 0;
    cout<<"Enter withdraw amount: ";
    cin>>amount;

    BankAccount* account = accounts[account_index];
    account->withdraw(amount);
}

//FREE FUNCTIONS
void display_menu()
{
    cout<<"\nACC Bank\n";
    cout<<"1-Display Balance\n";
    cout<<"2-Make Deposit\n";
    cout<<"3-Make Withdraw\n";
    cout<<"4-Exit\n";
}

void run_menu(ATM &atm)
{
    auto choice = 0;

    do
    {
        display_menu();
        cout<<"Enter menu choice: ";
        cin>>choice;
        handle_user_choice(choice, atm);

    } while (choice !=4);
    
}

void handle_user_choice(int choice, ATM &atm)
{
    switch(choice)
    {
        case 1:
            atm.display_balance();
            break;
        case 2:
            atm.make_deposit();
            break;
        case 3:
            atm.make_withdraw();
            break;
        case 4:
            cout<<"Program will exit\n";
            break;
        default:
            cout<<"Invalid Option";
    }
}
