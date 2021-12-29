#include"Heathcliff.h"
Heathcliff::Heathcliff() :People("Heathcliff", 3000, 0, 3) {
	;
}
// ¥u·|»ë 1 5 6
void Heathcliff::rollDiceNum(Dice*& ptr) {
	int dice_kirito = Dice::randomInt(1, 3);
	if (dice_kirito == 1) {
		ptr->setRollDice(1);
	}
	else if (dice_kirito == 2) {
		ptr->setRollDice(5);
	}
	else  if (dice_kirito == 3) {
		ptr->setRollDice(6);
	}

};