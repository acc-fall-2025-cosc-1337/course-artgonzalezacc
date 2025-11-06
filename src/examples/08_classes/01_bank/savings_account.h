//savings_account.h
#include "bank_account.h"
#include<iostream>

#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount: public BankAccount
{
public:
    SavingsAccount(){}
    SavingsAccount(int b) : BankAccount(b){}
    int get_balance() const{std::cout<<"Savings.get_balance: "; return (BankAccount::get_balance() * RATE) + BankAccount::get_balance();}
private: 
    double RATE{.1};
};

#endif