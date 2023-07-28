//
#include<iostream>
#include<stdlib.h>

#ifndef DIE_H
#define DIE_H

class Die 
{
public:
    void roll();                         //Randomly assigns a value to roll_value in the range of 1 to 6
    int rolled_value() const;            //Returns roll_value

private:
    int roll_value;                      //Stores a randomly assigned value
    int sides {6};                       //Die sides, initialized to 6
};

#endif