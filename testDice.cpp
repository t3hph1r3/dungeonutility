//
// Created by kevin hublou on 3/3/16.
//

#include <iostream>
#include "dice.h"

using namespace std;

int main() {
    int* dArray = Dice::rollMore(4, 6);
    for(int i = 0; i < 4; i++) {
        cout << dArray[i] << "," << ends;
        int str = Dice::abilityScore();
        cout << "Str is " << str << endl;

    }
    delete(dArray);
    return 0;
}