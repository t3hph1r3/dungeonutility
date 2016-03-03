#include <iostream>
#include "dice.h"

using namespace std;

int main() {
    int* dArray = Dice::rollMore(4, 6);
    for(int i = 0; i < 4; i++) {
        cout << dArray[i] << "," << ends;

    }
    return 0;
}