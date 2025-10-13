#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "function_vec.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test use_vector_val_param demonstrates value parameter behavior", "[vector][value_param]") {
	std::vector<int> vec = {1, 2, 3};
	use_vector_val_param(vec);

	// The original vector should remain unchanged after the function call
	REQUIRE(vec.size() == 3);
	REQUIRE(vec[0] == 1);
	REQUIRE(vec[1] == 2);
	REQUIRE(vec[2] == 3);
}


