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
    static int* rollMore(int times, int sides);
};


int Dice::roll(int sides) {
    long result = random();
    result = ((result % sides) + 1);
    if (result < 0) {result = result * -1;}
    return (int) result;
}

int* Dice::rollMore(int times, int sides){
    int* results = new int[times];
    for(int i = 0; i < times; i++){
        results[i] = roll(sides);
    }
    return results;
}


#endif //DUNGEONUTILITY_DICE_H
