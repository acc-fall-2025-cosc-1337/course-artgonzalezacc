#include "atm.h"
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "bank_account_db.h"
#include <ctime>   // For time()
#include<memory>

using std::cout;
using std::unique_ptr; using std::make_unique;
using std::vector;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;

	vector<unique_ptr<BankAccount>> accounts;
	accounts.push_back(make_unique<SavingsAccount>(db.get_balance()));
	
	accounts.push_back(make_unique<SavingsAccount>(db.get_balance()));

	accounts.push_back(make_unique<CheckingAccount>(db.get_balance()));

	ATM atm(accounts);

	run_menu(atm);

	return 0;
}