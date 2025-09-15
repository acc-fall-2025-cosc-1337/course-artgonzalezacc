#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"

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

TEST_CASE("is_vowel function", "[is_vowel]") {
	REQUIRE(is_vowel('a') == true);
	REQUIRE(is_vowel('e') == true);
	REQUIRE(is_vowel('i') == true);
	REQUIRE(is_vowel('o') == true);
	REQUIRE(is_vowel('u') == true);
	REQUIRE(is_vowel('b') == false);
	REQUIRE(is_vowel('y') == false);
}

TEST_CASE("is_consonant function", "[is_consonant]") {
	REQUIRE(is_consonant('a') == false);
	REQUIRE(is_consonant('e') == false);
	REQUIRE(is_consonant('i') == false);
	REQUIRE(is_consonant('o') == false);
	REQUIRE(is_consonant('u') == false);
	REQUIRE(is_consonant('b') == true);
	REQUIRE(is_consonant('y') == true);
}