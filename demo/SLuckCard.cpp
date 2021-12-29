#include"SLuckCard.h"
SLuckCard::SLuckCard() : MissionCard("超幸運卡", "踩到任務的人多1000元且自己房子全數升級")
{
    
}

void SLuckCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 1000); // 加自己500
	for (int i = 0; i < 32; i++) { // 所有自己的房子被多蓋一層, 不用花錢
		if (ptr3[i]) { // 是房屋格
			if (ptr3[i]->getOwner() == ptr1) { // owner 是自己
				int maxhousenum = ptr3[i]->getHouseNum() + 1 > 4 ? 4 : ptr3[i]->getHouseNum() + 1; // 最大就4
				ptr3[i]->setHouseNum(maxhousenum);
			}
		}
	}
}
