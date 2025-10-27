#include "atm.h"
#include "bank_account.h"

int main()
{
	BankAccount account(150);
	display_account_balance(account);

	ATM atm(account);

	atm.display_balance();

	atm.make_deposit();

	display_account_balance(account);

	atm.display_balance();

	return 0;
}