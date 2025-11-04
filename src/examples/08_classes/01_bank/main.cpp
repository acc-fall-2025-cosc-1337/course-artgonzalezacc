#include "atm.h"
#include "bank_account.h"
#include "bank_account_db.h"
#include <ctime>   // For time()

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;
	BankAccount account(db.get_balance());

	ATM atm(account);

	run_menu(atm);

	display_account_balance(account);

	return 0;
}