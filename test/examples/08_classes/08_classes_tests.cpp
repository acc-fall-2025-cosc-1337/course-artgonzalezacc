#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"
#include "checking_account.h"
#include "bank_account_db.h"
#include <ctime>   // For time()

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("test get balance") 
{
	CheckingAccount account;//create a variable---> create an object
	REQUIRE(0 == account.get_balance());
}

TEST_CASE("test get account function")
{
	int begin_balance = 250;
	BankAccount account = get_account(begin_balance);
	REQUIRE(account.get_balance() == begin_balance);
}

TEST_CASE("test deposit with positive amount") 
{
	int begin_balance = 500;

	BankAccount account(begin_balance);
	REQUIRE(begin_balance == account.get_balance());

	account.deposit(50);

	REQUIRE(550 == account.get_balance());
}

TEST_CASE("test deposit with negative amount")
{
	int begin_balance = 500;
	BankAccount account(begin_balance);

	REQUIRE(begin_balance == account.get_balance());

	account.deposit(-50);

	REQUIRE(begin_balance == account.get_balance());
}

TEST_CASE("test withdraw positive amount; amount lt balance") 
{
	int begin_balance = 500;
	BankAccount account(begin_balance);

	REQUIRE(begin_balance == account.get_balance());

	account.withdraw(100);
	REQUIRE(400 == account.get_balance());
}

TEST_CASE("test withdraw with negative amout")
{
	int begin_balance = 500;
	BankAccount account(begin_balance);

	REQUIRE(begin_balance == account.get_balance());

	account.withdraw(-100);

	REQUIRE(begin_balance == account.get_balance());
}

TEST_CASE("test deposit and withdraw amount")
{
	int begin_balance = 500;
	BankAccount account(begin_balance);

	REQUIRE(begin_balance == account.get_balance());

	account.deposit(100);

	REQUIRE(600 == account.get_balance());

	account.withdraw(100);

	REQUIRE(begin_balance == account.get_balance());
}

TEST_CASE("test withdraw and deposit amount")
{
	int begin_balance = 500;
	BankAccount account(begin_balance);

	REQUIRE(begin_balance == account.get_balance());

	account.withdraw(100);
	REQUIRE(400 == account.get_balance());

	account.deposit(100);
	REQUIRE(begin_balance == account.get_balance());
}

TEST_CASE("test bank account db initialize balance ")
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;

	REQUIRE(db.get_balance() >= 1);
	REQUIRE(db.get_balance() <= 10000);
}

TEST_CASE("test bank account db initialize balance|init Bank account")
{
	srand(static_cast<unsigned int>(time(0)));
	BankAccountDB db;
	BankAccount account(db.get_balance());

	REQUIRE(account.get_balance() >= 1);
	REQUIRE(account.get_balance() <= 10000);
}