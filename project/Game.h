#pragma once
#include"InputHandler.h"
#include"Display.h"
#include"Dice.h"
#include"House.h"
#include"Map.h"
#include"People.h"
#include"Kirito.h"

#include"MissionCard.h"
#include"TestCard.h"

#define NUMOFCARDS 40
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
				ptrPeople[i] = new People;
			}
			else if (chooseOrder[i] == 2) {
				ptrPeople[i] = new People;
			}
			else {
				ptrPeople[i] = new People;
			}
			ptrPeople[i]->setOrder(i);
		}

		ptrMap = new Map;

		ptrCards = new MissionCard*[NUMOFCARDS];
		cardsArray = new int[NUMOFCARDS];
		for (int i = 0; i < NUMOFCARDS; i++)
			cardsArray[i] = 0;
		for (int i = 0; i < NUMOFCARDS; i++) {
			if (cardsArray[i] == 0) {
				ptrCards[i] = new TestCard();
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

