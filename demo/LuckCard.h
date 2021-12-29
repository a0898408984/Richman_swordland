#pragma once
#include"MissionCard.h"
class LuckCard : public MissionCard 
{
public:
	LuckCard();
	~LuckCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
