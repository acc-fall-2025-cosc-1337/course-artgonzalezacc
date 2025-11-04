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

void display_menu();
void run_menu(ATM &atm);
void handle_user_choice(int choice, ATM &atm);

#endif
