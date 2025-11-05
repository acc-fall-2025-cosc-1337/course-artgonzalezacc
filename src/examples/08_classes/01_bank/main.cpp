#include "atm.h"
#include "bank_account.h"
#include "bank_account_db.h"
#include <ctime>   // For time()

using std::vector;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;
	vector<BankAccount> accounts;
	accounts.push_back(BankAccount(db.get_balance()));
	
	accounts.push_back(BankAccount(db.get_balance()));

	accounts.push_back(BankAccount(db.get_balance()));

	ATM atm(accounts);

	run_menu(atm);

	return 0;
}