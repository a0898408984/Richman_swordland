#pragma once
#include"MissionCard.h"
class SJinxCard : public MissionCard 
{
public:
	SJinxCard();
	~SJinxCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
