//
#include<iostream>
#include<memory>
#include<vector>
#include "die.h"
#include "roll.h"

using std::unique_ptr; 
using std::make_unique;
using std::vector;
using std::ostream;
using std::cout;

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
public:
    Roll* throw_die(Die& die1, Die& die2);
    friend ostream& operator<<(ostream& os, const Shooter& shooter_ref);
    ~Shooter();

private:
    vector<Roll*> rolls;
};

#endif
