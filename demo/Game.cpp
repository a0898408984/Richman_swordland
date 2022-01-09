#include"Game.h"
#include<algorithm>
#include<fstream>
#define SAVEFILEMAPNOTHOUSE -128763
#define SAVEFILEMAPNOTOWNER -12876300
#define SAVEFILEENDING -102040240
#define SAVEFILEENDINGSTR "-102040240"
#define SAVEGAMEPATH "saveGame.txt"
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
void Game::loadCardAndPeople() {
	ptrPeople = new People * [numOfPlayers];
	for (int i = 0; i < numOfPlayers; i++) {
		if (chooseCharOrder[i] == 0) {
			ptrPeople[i] = new Kirito;
		}
		else if (chooseCharOrder[i] == 1) {
			ptrPeople[i] = new Asuna;
		}
		else if (chooseCharOrder[i] == 2) {
			ptrPeople[i] = new Klein;
		}
		else {
			ptrPeople[i] = new Heathcliff;
		}
		ptrPeople[i]->setOrder(i);
	}
	ptrCards = new MissionCard * [NUMOFCARDS];
	for (int i = 0; i < NUMOFCARDS; i++) {
		if (cardsArray[i] == 0) {
			ptrCards[i] = new TestCard();
		}
		else if (cardsArray[i] == TYPECARDS) {
			ptrCards[i] = new LuckCard();
		}
		else if (cardsArray[i] + 1 == TYPECARDS) {
			ptrCards[i] = new SLuckCard();
		}
		else if (cardsArray[i] + 2 == TYPECARDS) {
			ptrCards[i] = new JinxCard();
		}
		else if (cardsArray[i] + 3 == TYPECARDS) {
			ptrCards[i] = new SJinxCard();
		}
		else if (cardsArray[i] + 4 == TYPECARDS) {
			ptrCards[i] = new ChangePosCard();
		}
		else if (cardsArray[i] + 5 == TYPECARDS) {
			ptrCards[i] = new PrisonCard();
		}
		else if (cardsArray[i] + 6 == TYPECARDS) {
			ptrCards[i] = new FastCard();
		}
		else if (cardsArray[i] + 7 == TYPECARDS) {
			ptrCards[i] = new FireCard();
		}
		else if (cardsArray[i] + 8 == TYPECARDS) {
			ptrCards[i] = new MFireCard();
		}
		else if (cardsArray[i] + 9 == TYPECARDS) {
			ptrCards[i] = new FortuneCard();
		}
	}
}
bool Game::run(){
	if (endGame)return true;
	// before start
	if (!newGame) 
		loadGame();
	if (newGame)
		loadCardAndPeople();

	// display 0
	ptrDisplay->display0();
	while (1) {
		// todo::autosave
		saveGame();
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


bool Game::saveGame() {
	std::fstream f;
	f.open(SAVEGAMEPATH, std::ios::out);
	if (!f.is_open())
		return false;
	f << numOfPlayers << std::endl;
	f << usedCards << std::endl;
	f << round << std::endl;
	f << who << std::endl;
	f << endGame << std::endl;
	for(int i = 0; i < numOfPlayers; i ++)
		f << chooseCharOrder[i] << std::endl;
	for(int i = 0; i < NUMOFCARDS; i ++)
		f << cardsArray[i] << std::endl;
	for(int i =0; i < numOfPlayers; i++)
		f << group1[i] << std::endl;
	for (int i = 0; i < numOfPlayers; i++)
		f << group2[i] << std::endl;
	for (int i = 0; i < numOfPlayers; i++)
		f << prison[i] << std::endl;

	// people
	for (int i = 0; i < numOfPlayers; i++) {
		f << ptrPeople[i]->getCash() << std::endl;
		f << ptrPeople[i]->getDeposit() << std::endl;
		f << ptrPeople[i]->getPos() << std::endl;
	}

	// map / house
	for (int i = 0; i < 32; i++) {
		if (!ptrMap->mapHouse[i])
			f << SAVEFILEMAPNOTHOUSE << std::endl; // -c8763 means nullptr
		else {
			f << ptrMap->mapHouse[i]->getHouseNum() << std::endl;
			People* tmpPtr = ptrMap->mapHouse[i]->getOwner();
			if(tmpPtr)
				f << ptrMap->mapHouse[i]->getOwner()->getOrder() << std::endl;
			else 
				f << SAVEFILEMAPNOTOWNER << std::endl;
		}
	}

	// dice
	f << ptrDice->getDiceNum() << std::endl;

	f << SAVEFILEENDING << std::endl;

	f.close();
	return true;
}

bool Game::loadGame() {
	std::fstream f;
	f.open(SAVEGAMEPATH, std::ios::in);
	if (!f.is_open()) {
		newGame = 1;
		return false;
	}
	f >> numOfPlayers >> usedCards >> round >> who >> endGame;
	delete[] chooseCharOrder;
	delete[] group1;
	delete[] group2;
	delete[] prison;

	chooseCharOrder = new int [numOfPlayers];
	group1 = new int[numOfPlayers];
	group2 = new int[numOfPlayers];
	prison = new int[numOfPlayers];
	int tmp;
	for (int i = 0; i < numOfPlayers; i++) {
		f >> tmp;
		chooseCharOrder[i] = tmp;
	}
	for (int i = 0; i < NUMOFCARDS; i++) {
		f >> tmp;
		cardsArray[i] = tmp;
	}
	for (int i = 0; i < numOfPlayers; i++) {
		f >> tmp;
		group1[i] = tmp;
	}
	for (int i = 0; i < numOfPlayers; i++) {
		f >> tmp;
		group2[i] = tmp;
	}
	for (int i = 0; i < numOfPlayers; i++) {
		f >> tmp;
		prison[i] = tmp;
	}

	loadCardAndPeople();

	// people
	for (int i = 0; i < numOfPlayers; i++) {
		int intTmp;
		double doubleTmp;
		f >> doubleTmp;
		ptrPeople[i]->setCash(doubleTmp);
		f >> doubleTmp;
		ptrPeople[i]->setDeposit(doubleTmp);
		f >> intTmp;
		ptrPeople[i]->setPos(intTmp);
	}

	// map / house
	for (int i = 0; i < 32; i++) {
		int tmp;
		f >> tmp;
		if (tmp != SAVEFILEMAPNOTHOUSE) {
			ptrMap->mapHouse[i]->setHouseNum(tmp);
			f >> tmp;
			if (tmp == SAVEFILEMAPNOTOWNER)
				continue;
			else
				ptrMap->mapHouse[i]->setOwner(ptrPeople[tmp]);
		}
		else
			continue;
	}
	// dice
	int tmpDice;
	f >> tmpDice;
	ptrDice->setRollDice(tmpDice);

	f.close();
	newGame = 0;
	return true;
}

