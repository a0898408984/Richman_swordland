#pragma once
#include"InputHandler.h"
#include"Display.h"
#include"Dice.h"
#include"House.h"
#include"Map.h"
#include"People.h"
#include"Kirito.h"
#include"Heathcliff.h"
#include"Klein.h"
#include"Asuna.h"

#include"MissionCard.h"
#include"TestCard.h"

#include"LuckCard.h"
#include"SLuckCard.h"
#include"JinxCard.h"
#include"SJinxCard.h"
#include"ChangePosCard.h"
#include"PrisonCard.h"
#include"FastCard.h"
#include"FireCard.h"
#include"MFireCard.h"
#include"FortuneCard.h"

#define NUMOFCARDS 500
#define TYPECARDS 10

class Display;
class Game
{
public:
	InputHandler* ptrInput;
	Display* ptrDisplay;
	People** ptrPeople;
	Map* ptrMap;
	MissionCard** ptrCards;
	Dice* ptrDice;

	// for save project
	int numOfPlayers;
	int usedCards = 0;
	int round = 0;
	int who = 0;
	bool endGame = 0;
	int* chooseCharOrder;
	int* cardsArray;
	int* group1;
	int* group2;
	int* prison;



	Game(int num, int* chooseOrder) {
		ptrDisplay = NULL;
		ptrInput = NULL;
		numOfPlayers = num;
		group1 = new int[num];
		group2 = new int[num];
		prison = new int[num];
		ptrPeople = new People * [num];
		chooseCharOrder = new int[num];
		for (int i = 0; i < num; i++) {
			group1[i] = 0;
			group2[i] = 0;
			prison[i] = 0;
			chooseCharOrder[i] = chooseOrder[i];
		}
		for (int i = 0; i < num; i++) {
			if (chooseOrder[i] == 0) {
				ptrPeople[i] = new Kirito;
			}
			else if (chooseOrder[i] == 1) {
				ptrPeople[i] = new Asuna;
			}
			else if (chooseOrder[i] == 2) {
				ptrPeople[i] = new Klein;
			}
			else {
				ptrPeople[i] = new Heathcliff;
			}
			ptrPeople[i]->setOrder(i);
		}

		ptrMap = new Map;

		ptrCards = new MissionCard*[NUMOFCARDS];
		cardsArray = new int[NUMOFCARDS];
		for (int i = 0; i < NUMOFCARDS; i++)
			cardsArray[i] = Dice::randomInt(1, TYPECARDS);
		//cardsArray[0] = 0;
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

		ptrDice = new Dice;
		who = 0;
	}
	~Game() {};
	
	void setinit(Display* d, InputHandler* i) { ptrDisplay = d; ptrInput = i; }

	// game
	bool run();
	void mapEvent(int,int);
	int getDiceNow() { return  ptrDice->getDiceNum(); }

	// end
	People** showRank();
	
	

private:

};

