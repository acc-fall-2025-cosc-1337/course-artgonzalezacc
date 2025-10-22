//bank_account.cpp
#include "bank_account.h"

using std::cout;

void display_account_balance(BankAccount &account)
{
    cout<<"Display account balance: "<<account.get_balance()<<"\n";
}