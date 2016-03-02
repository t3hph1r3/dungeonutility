//
// Created by k on 3/1/16.
//

#ifndef DUNGEONUTILITY_DICE_H
#define DUNGEONUTILITY_DICE_H

#include <iostream>
#include <random>
#include <chrono>

class Dice{

private:

public:
    static int roll(int sides);
};


int Dice::roll(int sides) {
    std::random_device random;
    long result = random();
    result = ((result % sides) + 1);
    if (result < 0) {result = result * -1;}
    return (int) result;
}


#endif //DUNGEONUTILITY_DICE_H