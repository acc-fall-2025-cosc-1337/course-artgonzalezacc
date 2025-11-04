#include <cstdlib> // For rand() and srand()

#ifndef BANK_ACCOUNT_DB_H
#define BANK_ACCOUNT_DB_H

class BankAccountDB
{
public:
    BankAccountDB(){initialize_balance();}
    int get_balance()const{return balance;}

private:
    void initialize_balance();
    int balance;
};


#endif