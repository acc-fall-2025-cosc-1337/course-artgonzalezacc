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
