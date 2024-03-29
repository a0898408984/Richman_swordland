#pragma once
#include<string>
#include"Dice.h"
#define INITIALMONEY 3000
#define INITIALDEPOSIT  0
#define INITIALNAME "noname"

class People{
public:
	People(std::string s = INITIALNAME, double cashmoney = INITIALMONEY, double depositmoney = INITIALDEPOSIT, int = 0); // 名字, 現金, 存款, 種類
	~People();
	int getDiceNum(Dice*&);
	virtual void rollDiceNum(Dice*& d) {
		d->setRollDice();
	};

	double getCash();
	double getDeposit();
	std::string getName();
	bool getDoubleHousePrice();
	int getId();
	int getPos();
	int getOrder();
	int getCharType() { return characterType; }
	
	void setName(std::string);
	void setCash(double);
	void setDeposit(double);
	void setDoubleHousePrice(bool);
	void setPos(int);
	void setOrder(int);

private:
	std::string name;
	double cash;
	double deposit;
	bool doubleHousePrice;
	int id;
	int pos;
	int characterType;
	int order;
};

