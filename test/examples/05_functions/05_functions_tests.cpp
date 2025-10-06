#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "val_ref.h"
#include "default.h"

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

TEST_CASE("Test show_area function", "area") {
	
	double expected_area = 200;

	// Assuming show_area returns the area as int
	double area = show_area();
	REQUIRE(area == expected_area);
}

TEST_CASE("Test show_area function, one argument", "area") {
	
	double expected_area = 100;

	// Assuming show_area returns the area as int
	double area = show_area(10);
	REQUIRE(area == expected_area);
}

TEST_CASE("Test show_area function, two arguments", "area") {
	
	double expected_area = 50;

	// Assuming show_area returns the area as int
	double area = show_area(10, 5);
	REQUIRE(area == expected_area);
}

TEST_CASE("Test get_biweekly_gross_pay", "[pay]") {
	// Test with typical values
	double annual_salary = 52000.0;
	double expected_biweekly = 2000.0; // 52000 / 26
	REQUIRE(get_biweekly_gross_pay(annual_salary) == Approx(expected_biweekly));

	// Test with zero salary
	annual_salary = 0.0;
	expected_biweekly = 0.0;
	REQUIRE(get_biweekly_gross_pay(annual_salary) == Approx(expected_biweekly));

	// Test with negative salary (should handle gracefully)
	annual_salary = -52000.0;
	expected_biweekly = -2000.0;
	REQUIRE(get_biweekly_gross_pay(annual_salary) == Approx(expected_biweekly));
}

TEST_CASE("Test get_biweekly_gross_pay with hours and rate", "[pay]") {
	// Typical case
	double hours = 80.0;
	double rate = 25.0;
	double expected_pay = 2000.0; // 80 * 25
	REQUIRE(get_biweekly_gross_pay(hours, rate) == Approx(expected_pay));

	// Zero hours
	hours = 0.0;
	rate = 30.0;
	expected_pay = 0.0;
	REQUIRE(get_biweekly_gross_pay(hours, rate) == Approx(expected_pay));

	// Zero rate
	hours = 80.0;
	rate = 0.0;
	expected_pay = 0.0;
	REQUIRE(get_biweekly_gross_pay(hours, rate) == Approx(expected_pay));

	// Negative hours
	hours = -80.0;
	rate = 25.0;
	expected_pay = -2000.0;
	REQUIRE(get_biweekly_gross_pay(hours, rate) == Approx(expected_pay));

	// Negative rate
	hours = 80.0;
	rate = -25.0;
	expected_pay = -2000.0;
	REQUIRE(get_biweekly_gross_pay(hours, rate) == Approx(expected_pay));

	// Both negative
	hours = -80.0;
	rate = -25.0;
	expected_pay = 2000.0;
	REQUIRE(get_biweekly_gross_pay(hours, rate) == Approx(expected_pay));
}