#pragma once
#include"MissionCard.h"
class PrisonCard : public MissionCard 
{
public:
	PrisonCard();
	~PrisonCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
