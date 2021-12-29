#pragma once
#include"MissionCard.h"
class FastCard : public MissionCard 
{
public:
	FastCard();
	~FastCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
