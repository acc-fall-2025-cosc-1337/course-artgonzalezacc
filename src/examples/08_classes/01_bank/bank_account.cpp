//bank_account.cpp
#include "bank_account.h"

using std::cout;

void display_account_balance(const BankAccount &account)
{
    cout<<"Display account balance: "<<account.get_balance()<<"\n";
}

BankAccount get_account(int balance)
{
    BankAccount account(balance);
    return account;
}