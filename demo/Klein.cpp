#include"Klein.h"
Klein::Klein() :People("Klein", 3000, 0, 2) {
	;
}

//¥u·|»ë¨ì 1,2,5,6
void Klein::rollDiceNum(Dice*& ptr) {
	int dice_kirito = Dice::randomInt(1, 4);
	if (dice_kirito == 1) {
		ptr->setRollDice(1);
	}
	else if (dice_kirito == 2) {
		ptr->setRollDice(2);
	}
	else  if (dice_kirito == 3) {
		ptr->setRollDice(5);
	}
	else if (dice_kirito == 4) {
		ptr->setRollDice(6);
	}
};