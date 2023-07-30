#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

/*
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
*/

//Test that ComeOutPhase get outcomes returns values RollOutcome::natural, RollOutcome::craps, and RollOutcome::point

TEST_CASE("Test ComeOutPhase::get_outcome returns values")
{
    Die roll1_test, roll2_test;
    Roll roll_test(roll1_test, roll2_test);

    roll_test.roll_die();
    int result = roll_test.roll_value();

    ComeOutPhase comeOutPhase;
    RollOutcome outcome = comeOutPhase.get_outcome(&roll_test);

    if (result == 7 || result == 11)
        REQUIRE(outcome == RollOutcome::natural);
    else if (result == 2 || result == 3 || result == 12)
        REQUIRE(outcome == RollOutcome::craps);
    else
        REQUIRE(outcome == RollOutcome::point);
}

//Test that PointPhase get outcomes returns values RollOutcome::point, RollOutcome::seven_out, and RollOutcome::nopoint 

TEST_CASE("Test PointPhase::get_outcome returns values")
{
    Die roll1_test, roll2_test;
    Roll roll_test(roll1_test, roll2_test);

    int pointValue = 6;
    PointPhase pointPhase(pointValue);

    roll_test.roll_die();
    int result = roll_test.roll_value();

    if (result == pointValue)
        REQUIRE(pointPhase.get_outcome(&roll_test) == RollOutcome::point);
    else if (result == 7)
        REQUIRE(pointPhase.get_outcome(&roll_test) == RollOutcome::seven_out);
    else
        REQUIRE(pointPhase.get_outcome(&roll_test) == RollOutcome::nopoint);
}