#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h"
#include "char.h"

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

TEST_CASE("Test add_doubles returns sum of two doubles", "[add_doubles]") {
	REQUIRE(add_doubles(0.0, 0.0) == 0.0);
	REQUIRE(add_doubles(1.1, 2.2) == Approx(3.3));
	REQUIRE(add_doubles(-5.5, 5.5) == 0.0);
	REQUIRE(add_doubles(100.0, 200.0) == 300.0);
	REQUIRE(add_doubles(-10.0, -20.0) == -30.0);
}

TEST_CASE("Test gross_pay returns correct pay", "[gross_pay]") {
	REQUIRE(gross_pay(40, 15.5) == Approx(620.0));
	REQUIRE(gross_pay(0, 20.0) == Approx(0.0));
	//REQUIRE(gross_pay(35, 10.33) == Approx(360.55));
	REQUIRE(gross_pay(50, 22.5) == Approx(1125.0));
	REQUIRE(gross_pay(10, 0.0) == Approx(0.0));
}

// Test case for get_char_ascii_value
TEST_CASE("Test get_char_ascii_value returns correct ASCII value", "[get_char_ascii_value]") {
	REQUIRE(get_char_ascii_value('A') == 65);
	REQUIRE(get_char_ascii_value('a') == 97);
	REQUIRE(get_char_ascii_value('0') == 48);
	REQUIRE(get_char_ascii_value('Z') == 90);
	REQUIRE(get_char_ascii_value('z') == 122);
	REQUIRE(get_char_ascii_value(' ') == 32);
	REQUIRE(get_char_ascii_value('\n') == 10);
}