#include"Dice.h"

int Dice::randomInt(int p, int q) {
    static int init = 0;
    if (init == 0) { srand((unsigned)time(NULL)), rand(), ++init; }
    return (int)((rand() / (RAND_MAX + 1.0)) * (q - p + 1.0) + p);
}
Dice::Dice()
{
    num = randomInt(1,6);
}

int Dice::getRandom() {
    num = randomInt(1, 6);
    return num;
}

int Dice::setRollDice() {
    return getRandom();
}

int Dice::setRollDice(int n) {
    num = n;
    return num;
}

int Dice::getDiceNum() {
    return num;
}

