#pragma once
#include"MissionCard.h"
class JinxCard : public MissionCard 
{
public:
	JinxCard();
	~JinxCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
