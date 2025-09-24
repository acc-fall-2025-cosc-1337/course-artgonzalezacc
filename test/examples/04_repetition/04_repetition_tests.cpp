#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include"while.h"
#include "do_while.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("sum_of_squares returns correct results", "[sum_of_squares]") 
{
	REQUIRE(sum_of_squares(0) == 0);
	REQUIRE(sum_of_squares(1) == 1);
	REQUIRE(sum_of_squares(2) == 5);   // 1^2 + 2^2 = 1 + 4 = 5
	REQUIRE(sum_of_squares(3) == 14);  // 1^2 + 2^2 + 3^2 = 1 + 4 + 9 = 14
	REQUIRE(sum_of_squares(5) == 55);  // 1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55
}

//Add test cases here to test the functions you create in do_while.h and do_while.cpp	
TEST_CASE("sum of squares returns correct results", "[sum_of_squares]") 
{
	REQUIRE(sum_of_squares_do(0) == 0);
	REQUIRE(sum_of_squares_do(1) == 1);
	REQUIRE(sum_of_squares_do(2) == 5);   // 1^2 + 2^2 = 1 + 4 = 5
	REQUIRE(sum_of_squares_do(3) == 14);  // 1^2 + 2^2 + 3^2 = 1 + 4 + 9 = 14
	REQUIRE(sum_of_squares_do(5) == 55);  // 1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55
}
