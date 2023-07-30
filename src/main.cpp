#include<iostream>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

using std::unique_ptr; 
using std::make_unique;
using std::vector;
using std::ostream;
using std::cout;

int main() 
{
    srand(time(0));  

    Die die1, die2;
    Shooter shooter;

    Roll* roll = shooter.throw_die(die1, die2);  

    ComeOutPhase come_out_phase;

    while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps) {

        cout<<"Rolled "<<roll->roll_value()<< " roll again.\n";

        roll = shooter.throw_die(die1, die2); 
    }

    cout<<"Rolled "<<roll->roll_value()<<" start of point phase.\n";
    cout<<"Roll until "<<roll->roll_value()<<" or 7 is rolled.\n";

    int point = roll->roll_value();  

    roll = shooter.throw_die(die1, die2);

    PointPhase point_phase(point);

    while (point_phase.get_outcome(roll) != RollOutcome::point && point_phase.get_outcome(roll) != RollOutcome::seven_out) {
        cout<<"Rolled "<< roll->roll_value()<<" roll again.\n";
 
        roll = shooter.throw_die(die1, die2);  
    }

    cout<<"Rolled "<<roll->roll_value()<<", end of point phase.\n";
    cout<<shooter;

	return 0;
}
