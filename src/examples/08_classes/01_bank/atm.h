//atm.h
#include "bank_account.h"

#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    ATM(BankAccount &a) : account(a) {/**empty code block */}
    void display_balance() { std::cout<<"Balance: "<<account.get_balance()<<"\n";};
    void make_deposit();
    void make_withdraw();

private:
    BankAccount& account;
};


#endif
