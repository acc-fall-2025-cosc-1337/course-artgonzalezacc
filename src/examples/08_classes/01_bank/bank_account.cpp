//bank_account.cpp
#include "bank_account.h"

using std::cout;

/**
 Class method/function
 */
void BankAccount::deposit(int amount)
{
    if(amount > 0) 
    {
        balance += amount;
    }
}

void BankAccount::withdraw(int amount)
{
    if(amount > 0 && amount < balance)
    {
        balance -= amount;
    }
}

/*FREE FUNCTION*/
void display_account_balance(const BankAccount &account)
{
    cout<<"Display account balance: "<<account.get_balance()<<"\n";
}

/*FREE FUNCTION*/
BankAccount get_account(int balance)
{
    BankAccount account(balance);
    return account;
}