#include"MFireCard.h"
MFireCard::MFireCard() : MissionCard("小火災", "出門記得關火,錢-700")
{
}

void MFireCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	ptr1->setCash(ptr1->getCash() - 700); // ?[??v500
	
}
