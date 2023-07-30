//
#include "die.h"

#ifndef ROLL_H
#define ROLL_H

class Roll
{
public:
    Roll(Die& roll1, Die& roll2) : die1(roll1), die2(roll2) {}       //With initializer list, initialize die1 and die2 Roll class private variables
    void roll_die();
    int roll_value() const;

private:
    Die& die1;                                                      //Initialize in Roll constructor
    Die& die2;
    bool rolled{false};                                             //Initialize to false
    int value;                                                
};

#endif