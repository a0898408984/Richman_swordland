#pragma once
#include<string>
#include"People.h"
#include"House.h"
#define INITIALNAME "noname"
#define INITIALDESCRIPTION "nodescription"
class MissionCard
{
public:
	MissionCard(std::string= INITIALNAME,std::string= INITIALDESCRIPTION);
	~MissionCard();
	std::string getName();
	std::string getDescription();

	virtual void show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {};
private:
	std::string name;
	std::string description;
};

