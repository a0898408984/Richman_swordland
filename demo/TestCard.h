#pragma once
#include"MissionCard.h"
class TestCard : public MissionCard 
{
public:
	TestCard();
	~TestCard() {};
	void show(People*, People**, House**);
private:

};
