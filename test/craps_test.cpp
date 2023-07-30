#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

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

TEST_CASE("Verify die rolls return a value from 2 to 12")
{
	Die roll1_test, roll2_test;
	Roll roll_test(roll1_test, roll2_test);
	
	roll_test.roll_die();
	int result = roll_test.roll_value();
		
	REQUIRE(result >= 2);
	REQUIRE(result <= 12);                         
}

TEST_CASE("Verify roll 10 times and assert each roll returns a value is from 2 to 12")
{
	Die roll1_test, roll2_test;
	Roll roll_test(roll1_test, roll2_test);
	
	for (int i = 0; i < 10; i++)
	{
		roll_test.roll_die();
		int result = roll_test.roll_value();
		
		REQUIRE(result >= 2);
		REQUIRE(result <= 12);    
	}
}