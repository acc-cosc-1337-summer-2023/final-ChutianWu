//
#include "shooter.h"

Roll* Shooter::throw_die(Die& die1, Die& die2)
{
    Roll* roll = new Roll(die1, die2);
    roll->roll_die();
    rolls.push_back(roll);
    return roll;
}

ostream& operator<<(ostream& os, const Shooter& shooter_ref)
{
    for (const auto& roll : shooter_ref.rolls)
    {
        os << "Output vector of Roll* is: " << roll->roll_value() << "\n";
    }
    return os;
}

Shooter::~Shooter()
{
    for(Roll* roll : rolls)
    {
        delete roll;
    }
}
