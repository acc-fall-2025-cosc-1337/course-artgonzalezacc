//bank_account.h
#include<iostream>
#include <cstdlib> // For rand() and srand()


#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount
{
    //variables and functions go here
public:
    BankAccount(){initialize_balance();}//default constructor 
    BankAccount(int b) : balance(b) {/**empty class function code block */}
    int get_balance() const { return balance; }
    void deposit(int amount);
    void withdraw(int amount);

private:
    int balance; //default value is 0
    void initialize_balance();

};

void display_account_balance(const BankAccount &account);
BankAccount get_account(int balance);

#endif