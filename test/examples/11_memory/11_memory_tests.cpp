#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ref_pointers.h"
#include "my_vector.h"

/*TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test value, reference, and pointer parameters")
{
	int num0 = 1;
	int num1 = 2;
	int num2 = 3;

	val_ref_ptr_params(num0, num1, &num2);

	REQUIRE(num0 == 1);
	REQUIRE(num1 == 20);
	REQUIRE(num2 == 30);
}

TEST_CASE("Test class shallow copy")
{
	MyVector v1(3);
	MyVector v2 = v1;//want to copy all the variables from v1 to v2
}

TEST_CASE("Test class copy assignment")
{
	MyVector v1(3);
	MyVector v2(3);
	v2 = v1;
}

TEST_CASE("Test my vector overwite with std::move")
{
	MyVector v1(3); //get memory for 3 elements in list
	MyVector v2 = std::move(v1); //invalidate v1, get v1's memory
}

TEST_CASE("Create v2 from function get_vector return value")
{
	MyVector v2(3);// memory created for v2
	v2 = get_vector();//overwrite v2 memory(freeing memory for v2 first)
}*/

TEST_CASE("Test push back my vector")
{
	MyVector v1(3);
	REQUIRE(0 == v1.Size());
	REQUIRE(3 == v1.Capacity());

	v1.PushBack(5);//???
	REQUIRE(5 == v1[0]);
	REQUIRE(1 == v1.Size());
	REQUIRE(3 == v1.Capacity());

	v1.PushBack(3);//???
	v1.PushBack(9);//???
	REQUIRE(3 == v1.Size());
	REQUIRE(3 == v1.Capacity());

	v1.PushBack(10);
	REQUIRE(4 == v1.Size());
	REQUIRE(6 == v1.Capacity());
}



