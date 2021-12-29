#include"Kirito.h"
Kirito::Kirito() :People ("Kirito", 3000, 0, 0){
	;
}



// 骰到高點的機會增加
void Kirito::rollDiceNum(Dice*& ptr) {
	int dice_kirito = Dice::randomInt(1, 10);

	if (dice_kirito == 1) {
		ptr->setRollDice(1);
	}
	else if (dice_kirito == 2) {
		ptr->setRollDice(2);
	}
	else  if (dice_kirito == 3) {
		ptr->setRollDice(3);
	}
	else if (dice_kirito <= 5) {
		ptr->setRollDice(4);
	}
	else if (dice_kirito <= 7) {
		ptr->setRollDice(5);
	}
	else if (dice_kirito <= 10) {
		ptr->setRollDice(6);
	}
};