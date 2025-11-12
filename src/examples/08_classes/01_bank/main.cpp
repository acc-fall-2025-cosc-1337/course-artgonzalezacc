#include "atm.h"
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "bank_account_db.h"
#include <ctime>   // For time()

using std::vector;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;
	BankAccount* ptr_account;	
	
	CheckingAccount checking(db.get_balance());//object (it's a variable)
	ptr_account = &checking; //pointers work with addresses
	std::cout<<ptr_account->get_balance()<<"\n";

	SavingsAccount savings(db.get_balance());
	ptr_account = &savings;
	std::cout<<ptr_account->get_balance()<<"\n";

	/*vector<BankAccount*> accounts;
	SavingsAccount savings0 = SavingsAccount(db.get_balance());
	accounts.push_back(&savings0);
	
	SavingsAccount savings1 = SavingsAccount(db.get_balance());
	accounts.push_back(&savings1);

	CheckingAccount checking = CheckingAccount(db.get_balance());
	accounts.push_back(&checking);

	ATM atm(accounts);

	run_menu(atm);*/

	return 0;
}