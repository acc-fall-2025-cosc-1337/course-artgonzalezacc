//atm.h
#include "bank_account.h"
#include <vector>
#include<memory>

#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    ATM(std::vector<std::unique_ptr<BankAccount>>& a);
    void display_balance();
    void make_deposit();
    void make_withdraw();

private:
    std::vector<std::unique_ptr<BankAccount>>& accounts;
    int account_index;
};

void display_menu();
void run_menu(ATM &atm);
void handle_user_choice(int choice, ATM &atm);

#endif
