#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else_if.h"
#include "switch.h"

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

TEST_CASE("testing")
{
	REQUIRE(get_generation(2030) == "Invalid Year");
	REQUIRE(get_generation(2000) == "Centenial");
	REQUIRE(get_generation(1990) == "Millenial");
	REQUIRE(get_generation(1970) == "Generation X");
	REQUIRE(get_generation(1950) == "Baby boomer");
	REQUIRE(get_generation(1930) == "Silent Generation");
	REQUIRE(get_generation(1600) == "Invalid Year");
}

TEST_CASE("menu_option function", "[menu_option]") {
	REQUIRE(menu_option(1) == "Option 1");
	REQUIRE(menu_option(2) == "Option 2");
	REQUIRE(menu_option(3) == "Option 3");
	REQUIRE(menu_option(4) == "Option 4");
	REQUIRE(menu_option(5) == "Invalid Option");
	REQUIRE(menu_option(-1) == "Invalid Option");
}	