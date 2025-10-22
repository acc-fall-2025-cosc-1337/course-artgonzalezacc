#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("test get balance") 
{
	BankAccount account0;
	BankAccount account(500);//create a variable---> create an object
	REQUIRE(500 == account.get_balance());
}

TEST_CASE("test get account function")
{
	int begin_balance = 250;
	BankAccount account = get_account(begin_balance);
	REQUIRE(account.get_balance() == begin_balance);
}