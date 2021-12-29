#pragma once
#include"MissionCard.h"
class FireCard : public MissionCard 
{
public:
	FireCard();
	~FireCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
