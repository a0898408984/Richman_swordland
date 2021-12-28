#pragma once
#include <stdio.h> 
#include <stdlib.h> 
#include<ctime> 
class Dice
{
public:
	Dice();
	int getDiceNum();  // "see" dice number
	int setRollDice();  // "set" and roll Dice 
	int setRollDice(int);  // "set" Dice 
	static int randomInt(int, int);  
private:
	int num;
	int getRandom();

};

