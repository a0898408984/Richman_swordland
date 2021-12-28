#include"MissionCard.h"
MissionCard::MissionCard(std::string s, std::string d)
{
	name = s;
	description = d;
}
MissionCard::~MissionCard()
{
}

std::string MissionCard::getDescription() {
	return description;
}

std::string MissionCard::getName() {
	return name;
}