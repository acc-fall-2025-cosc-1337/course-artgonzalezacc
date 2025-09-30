#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "val_ref.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test Value Parameter", "verification") {
	int num = 10;// original value(variable)
	func_value_param(num);
	REQUIRE(num == 10);
}

TEST_CASE("Test Reference Parameter", "verification") {
	int num = 10;// original value(variable)
	func_ref_param(num);
	REQUIRE(num == 30);
}
