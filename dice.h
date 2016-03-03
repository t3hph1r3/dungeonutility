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
    static int roll(int sides);     //Generates random number between 1 and 'sides.'
    static int* rollMore(int times, int sides);     //Generates 'times' random numbers between 1 and 'sides.'
    static int abilityScore();      //Generates standard ability scores using 4d6 drop the lowest roll method.
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

int Dice::abilityScore() {
    int* fourD6 = Dice::rollMore(4, 6); //create initial array of 4d6
    int lowest, score;      //track lowest roll, and total score
    lowest = fourD6[0];     //first roll is arbitrary 'lowest'
    score = lowest;     //will skip fourD6[0]
    for(int i = 1; i < 4; i++){
        score = score + fourD6[i];
        if(fourD6[i] < lowest){lowest = fourD6[i];}
    }
    score = score - lowest;
    delete(fourD6);
    return score;
}

#endif //DUNGEONUTILITY_DICE_H

