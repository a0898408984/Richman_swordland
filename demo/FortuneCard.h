#pragma once
#include"MissionCard.h"
class FortuneCard : public MissionCard 
{
public:
	FortuneCard();
	~FortuneCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
