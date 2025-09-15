#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("AND Truth Table", "[and]") {
	REQUIRE((false && false) == false);
	REQUIRE((false && true) == false);
	REQUIRE((true && false) == false);
	REQUIRE((true && true) == true);
}

TEST_CASE("OR Truth Table", "[or]") {
	REQUIRE((false || false) == false);
	REQUIRE((false || true) == true);
	REQUIRE((true || false) == true);
	REQUIRE((true || true) == true);
}

TEST_CASE("NOT Truth Table", "[not]") {
	REQUIRE((!false) == true);
	REQUIRE((!true) == false);
}