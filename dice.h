//
// Created by k on 3/1/16.
//edited by perry 3/4/16
//

#ifndef DUNGEONUTILITY_DICE_H
#define DUNGEONUTILITY_DICE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Dice{

private:
public:
    static int roll(int sides);     //Generates random number between 1 and 'sides.'
    static int* rollMore(int times, int sides);     //Generates 'times' random numbers between 1 and 'sides.'
    static int abilityScore();      //Generates standard ability scores using 4d6 drop the lowest roll method.
    static int* att(int bonus);       //Attack roll with d20 (alerts if 1 or 20), adds 'bonus' to roll.
};


int Dice::roll(int sides) {
    int check = rand();
    std::cout << check << std::endl;
    if(check == 1804289383){srand((unsigned int) time(NULL));} //Checks for default rand() seed and reseeds.
    int result = ((rand() % sides) + 1);
    if (result < 0) {result = result * -1;}
    return result;
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

int* Dice::att(int bonus) {
    int att[3] = {0,0,0};     //att[0] stores the attack roll, att[1] indicates crit/fumble, att[2] is roll + bonus
    att[0] = roll(20);
    if(att[0] == 1){att[1] = -1;}    //att[1] is -1 if attack roll is a fumble (rolls 1)
    else if (att[0] == 20){att[1] = 1;}    //att[1] is 1 if attack roll is a crit (rolls 20)
    att[2] = att[0] + bonus;      //att[2] is total attack roll -- roll + bonus
    return att;
}


#endif //DUNGEONUTILITY_DICE_H

