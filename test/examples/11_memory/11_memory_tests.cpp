#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ref_pointers.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test value, reference, and pointer parameters")
{
	int num0 = 1;
	int num1 = 2;
	int num2 = 3;

	val_ref_ptr_params(num0, num1, &num2);

	REQUIRE(num0 == 1);
	REQUIRE(num1 == 20);
	REQUIRE(num2 == 30);
}
