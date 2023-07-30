//
#include "shooter.h"

unique_ptr<Roll> Shooter::throw_die(Die& die1, Die& die2)
{
    unique_ptr<Roll> roll = make_unique<Roll>(die1, die2);
    roll->roll_die();
    rolls.push_back(make_unique<Roll>(die1, die2));
    rolls.back()->roll_die();
    return roll;
}

ostream& operator<<(ostream& os, const Shooter& shooter_ref)
{
    for(const auto& roll : shooter_ref.rolls)
    {
        os<<"Output vector of Roll* is: "<<roll->roll_value()<<"\n";
    }
    return os;
}
