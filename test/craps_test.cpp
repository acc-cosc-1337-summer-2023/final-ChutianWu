#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die rolls return a value from 1 to 6")
{
	Die die_test;
	
	die_test.roll();
	int result = die_test.rolled_value();
		
	REQUIRE(result >= 1);
	REQUIRE(result <= 6);                          //didn't write as REQUIRE((result >= 1) && (result <=6)) because it has errors;
}

TEST_CASE("Verify roll 10 times and each roll returns a value is from 1 to 6")
{
	Die die_test;
	
	for (int i = 0; i < 10; i++)
	{
		die_test.roll();
		int result = die_test.rolled_value();
		
		REQUIRE(result >= 1);
		REQUIRE(result <= 6); 
	}
}