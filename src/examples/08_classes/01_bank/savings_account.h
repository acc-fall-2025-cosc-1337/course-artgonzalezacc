//savings_account.h
#include "bank_account.h"

#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount: public BankAccount
{
public:
    SavingsAccount(){}
    SavingsAccount(int b) : BankAccount(b){}
};

#endif