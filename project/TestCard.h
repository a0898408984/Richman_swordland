#pragma once
#include"MissionCard.h"
class TestCard : public MissionCard 
{
public:
	TestCard();
	~TestCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
