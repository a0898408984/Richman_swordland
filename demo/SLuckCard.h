#pragma once
#include"MissionCard.h"
class SLuckCard : public MissionCard 
{
public:
	SLuckCard();
	~SLuckCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
