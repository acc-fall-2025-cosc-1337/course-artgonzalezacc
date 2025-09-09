#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test echo_variable returns input value", "[echo_variable]") {
	REQUIRE(echo_variable(0) == 0);
	REQUIRE(echo_variable(42) == 42);
	REQUIRE(echo_variable(-7) == -7);
	REQUIRE(echo_variable(123456) == 123456);
}

TEST_CASE("Test add_numbers returns sum of two integers", "[add_numbers]") {
	REQUIRE(add_numbers(0, 0) == 0);
	REQUIRE(add_numbers(1, 2) == 3);
	REQUIRE(add_numbers(-5, 5) == 0);
	REQUIRE(add_numbers(100, 200) == 300);
	REQUIRE(add_numbers(-10, -20) == -30);
}

/*test case echo_variable */

/*test case add_to_double_1 with 0 as parameter*/

/*test case add_to_double_1 with 1 as parameter*/

/*test case add_to_double_2 with 0 as parameter*/

/*test case add_to_double_2 with 1 as parameter*/

/*test case char test ASCII values */

/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/

