#include"Game.h"
#include"Display.h"
#include"InputHandler.h"

using namespace std;


int main(int argc, char* argv[]) {

	// display_3 ( opening menu)
	// wait input_3 ( new game, continue game, end game ... )

	// display_2  (choose gamer number)
	// wait input_2 (input gamer number)
	int num = Dice::randomInt(2,4);
	int* chooseOrder= new int[num];
	for (int i = 0; i < num; i++) {
		// display_1
		// wait input_1 (input gamer character
		chooseOrder[i] = Dice::randomInt(0, 3);
	}
	InputHandler* ptrInput = new InputHandler();
	Game* ptrGame = new Game(num, chooseOrder);
	Display* ptrDisplay = new Display(ptrGame, ptrInput);
	ptrGame->setinit(ptrDisplay, ptrInput);
	ptrGame->run();
	// display13
	ptrDisplay->display13();
	return 0;
}