#include "atm.h"
#include "bank_account.h"
#include "bank_account_db.h"
#include <ctime>   // For time()

using std::vector;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;
	BankAccount account(db.get_balance());
	vector<BankAccount&> accounts;
	accounts.push_back(account);
	
	BankAccount account1(db.get_balance());
	accounts.push_back(account1);

	BankAccount account2(db.get_balance());
	accounts.push_back(account2);

	ATM atm(accounts);

	run_menu(atm);

	display_account_balance(account);

	return 0;
}