#pragma once
#include"MissionCard.h"
class MFireCard : public MissionCard 
{
public:
	MFireCard();
	~MFireCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
