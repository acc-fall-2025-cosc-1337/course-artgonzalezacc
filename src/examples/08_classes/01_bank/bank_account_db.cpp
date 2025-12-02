#include "bank_account_db.h"

void BankAccountDB::initialize_balance()
{
    balance = (rand() % 10000) + 1;
}
