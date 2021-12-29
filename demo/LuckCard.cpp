#include"LuckCard.h"
LuckCard::LuckCard() : MissionCard("幸運卡", "踩到任務的人多500元")
{
}

void LuckCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 500); // 加自己500
	
}
