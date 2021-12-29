#include"Asuna.h"
Asuna::Asuna() :People("Asuna", 3000, 0, 1) {
	;
}

// ¤£·|»ë¨ì1 6
void Asuna::rollDiceNum(Dice*& ptr) {
	int dice_kirito = Dice::randomInt(2, 5);
	ptr->setRollDice(dice_kirito);
};