#include"Game.h"
#include<algorithm>


void Game::mapEvent(int nextPos, int who) {
	int status = ptrMap->maptile(nextPos);
	if (status == 0) {
		House* tmpptr = ptrMap->mapHouse[nextPos];
		if (!tmpptr->getOwner()) { // no owner. buy?
			if (tmpptr->checkBuildHouse(ptrPeople[who])) { // can buy
				// display 3 ( buy 
				ptrDisplay->display3();
				// wait input2 ( yes or no
				tmpptr->buildHouse(ptrPeople[who]);
				// display 0
				ptrDisplay->display0();
			}
		}
		else {
			if (tmpptr->sameOwner(ptrPeople[who])) { // buy house?
				if (tmpptr->checkBuildHouse(ptrPeople[who])) { // can buy
					// display 4 ( buy house
					ptrDisplay->display4();
					// wait input2 ( yes or no
					tmpptr->buildHouse(ptrPeople[who]);
					// display 0
					ptrDisplay->display0();
				}
			}
			else {
				// display 5 ( tolls
				ptrDisplay->display5();
				double tolls = tmpptr->getTolls();
				ptrPeople[who]->setCash(ptrPeople[who]->getCash() - tolls);
				tmpptr->getOwner()->setCash(tmpptr->getOwner()->getCash() + tolls);
				// wait input3 (information
				// display 0
				ptrDisplay->display0();
			}
		}
	}
	else if (status == 1) {
		;
	}
	else if (status == 2) {
		// display 0
		ptrDisplay->display0();

		// display 6 ( teleport to where
		ptrDisplay->display6();
		// wait input4 ( input Pos 0~31
		int input = Dice::randomInt(0,31);
		ptrPeople[who]->setPos(input);

		// display 0
		ptrDisplay->display0();
		return mapEvent(input, who);
	}
	else if (status == 3) {
		// display 7 ( show card info
		ptrDisplay->display7();
		ptrCards[usedCards]->show(ptrPeople[who],ptrPeople,numOfPlayers,ptrMap->mapHouse);
		usedCards++;
		// wait input3 ( information
		// display 0
		ptrDisplay->display0();
	}
	else if (status == 4) {
		if (nextPos == 21) {
			if (!group1[who] && !group2[who]) {
				// display 8 ( join group1)
				ptrDisplay->display8();
				// wait input3 ( information
				group1[who] = 1;
				// display 0
				ptrDisplay->display0();
			}
		}
		else {
			if (!group1[who] && !group2[who]) {
				// display 9 ( join group2)
				ptrDisplay->display9();
				// wait input3 ( information
				group2[who] = 1;
				// display 0
				ptrDisplay->display0();
			}
		}
	}
	else if (status == 5) {
		;
	}
	else if (status == 6) {
		// display 10 ( who in prison
		ptrDisplay->display10();
		prison[who]++;
		// display 0
		ptrDisplay->display0();
	}
	else if (status == 7) {
		;
	}
}
bool Game::run(){
	if (endGame)return true;
	// display 0
	ptrDisplay->display0();
	while (1) {
		// todo::autosave

		who = round % numOfPlayers;
		if (prison[who]) {
			prison[who]--;
			round++;
			// display 12
			ptrDisplay->display12();
			continue;
		}
		// wait input1 ( space
		ptrPeople[who]->rollDiceNum(ptrDice);
		// display 1
		ptrDisplay->display1();

		// display 0
		ptrDisplay->display0();
		int nextPos = ptrPeople[who]->getPos() + ptrPeople[who]->getDiceNum(ptrDice);
		if (nextPos >= 32) {// pass origin
			nextPos %= 32;
			ptrPeople[who]->setCash(ptrPeople[who]->getCash() + PASSORIGIN);
		}
		// display 0
		ptrDisplay->display0();
		// display 2 ( moving
		ptrDisplay->display2(ptrPeople[who]->getPos(), nextPos);
		ptrPeople[who]->setPos(nextPos);
		// display 0
		ptrDisplay->display0();
		mapEvent(nextPos, who);
		
		for (int i = 0; i < numOfPlayers; i++) {
			if (ptrPeople[i]->getCash() < 0) { // sell 
				for (int j = 0; j < 32; j++) { // temporary bad algo
					if (ptrMap->mapHouse[j]) {
						if (ptrMap->mapHouse[j]->sameOwner(ptrPeople[i])) {
							// display 11 ( sell building
							ptrDisplay->display11(j);
							ptrPeople[i]->setCash(ptrPeople[i]->getCash() + ptrMap->mapHouse[j]->getSumOfPrice() * 0.5);
							ptrMap->mapHouse[j]->sellToBank();
							// wait input3 ( information
							// display 0
							ptrDisplay->display0();
						}
					}
					if (ptrPeople[i]->getCash() >= 0) {
						break;
					}
				}
			}
		}
		for (int i = 0; i < numOfPlayers; i++) {
			if (ptrPeople[i]->getCash() < 0) {
				endGame = 1;
				break;
			}
		}
		if (endGame)break;
		round++;
	}
	return true;
}

bool compare1(People* a, People* b) {
	return a->getCash() >= b->getCash();
}
People** Game::showRank() {
	std::sort(ptrPeople,ptrPeople+4, compare1);
	return this->ptrPeople;
}