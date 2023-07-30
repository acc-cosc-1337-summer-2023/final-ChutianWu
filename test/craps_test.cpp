#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

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

TEST_CASE("Verify Shooter returns a Roll and the roll result has one of the following values: 2-12, loop 10 times")
{
    Die s_die1, s_die2; 
    Shooter shooter_test;

    for (int i = 0; i < 10; i++)
    {
       	auto roll = shooter_test.throw_die(s_die1, s_die2);
		int result = roll->roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}




