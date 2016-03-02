#include <iostream>
#include "dice.h"

using namespace std;

int main() {
    int d6;
    for(int i = 0; i < 10; i++) {
        d6 = Dice::roll(6);
        cout << d6 << endl;

    }
    return 0;
}