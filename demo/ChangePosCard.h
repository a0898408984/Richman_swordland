#pragma once
#include"MissionCard.h"
class ChangePosCard : public MissionCard 
{
public:
	ChangePosCard();
	~ChangePosCard() {};
	void show(People* ptr1, People** ptr2, int playerNum, House** ptr3);
private:

};
