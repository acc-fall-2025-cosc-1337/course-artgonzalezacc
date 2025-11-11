//atm.h
#include "bank_account.h"
#include <vector>

#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    ATM(std::vector<BankAccount*>& a);
    void display_balance();
    void make_deposit();
    void make_withdraw();

private:
    std::vector<BankAccount*> accounts;
    int account_index;
};

void display_menu();
void run_menu(ATM &atm);
void handle_user_choice(int choice, ATM &atm);

#endif
