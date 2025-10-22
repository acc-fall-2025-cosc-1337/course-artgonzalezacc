//bank_account.h
#include<iostream>

class BankAccount
{
    //variables and functions go here
public:
    BankAccount(){}//default constructor 
    BankAccount(int b) : balance(b) {/**empty class function code block */}
    int get_balance() const { return balance; }

private:
    int balance; //default value is 0

};

void display_account_balance(BankAccount &account);
