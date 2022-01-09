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
	bool newGame = 0;
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
		chooseCharOrder = new int[num];
		for (int i = 0; i < num; i++) {
			group1[i] = 0;
			group2[i] = 0;
			prison[i] = 0;
			chooseCharOrder[i] = chooseOrder[i];
		}

		ptrMap = new Map;

		cardsArray = new int[NUMOFCARDS];
		for (int i = 0; i < NUMOFCARDS; i++)
			cardsArray[i] = Dice::randomInt(1, TYPECARDS);


		ptrDice = new Dice;
		who = 0;
	}
	~Game() {};
	
	void setinit(Display* d, InputHandler* i) { ptrDisplay = d; ptrInput = i; }

	// game
	bool run();
	void mapEvent(int,int);
	int getDiceNow() { return  ptrDice->getDiceNum(); }
	bool saveGame();
	bool loadGame();
	void loadCardAndPeople();
	void setNewGame() { newGame = 1; } // before GameRun
	void setContGame() { newGame = 0; } // before GameRun

	// end
	People** showRank();
	
private:
};

