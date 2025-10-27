//atm.cpp
#include "atm.h"

using std::cin;
using std::cout;

void ATM::make_deposit()
{
    auto amount = 0;
    cout<<"Enter deposit amount: ";
    cin>>amount;

    account.deposit(amount);
}

void ATM::make_withdraw()
{
    auto amount = 0;
    cout<<"Enter withdraw amount: ";
    cin>>amount;

    account.withdraw(amount);
}