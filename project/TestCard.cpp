#include"TestCard.h"
TestCard::TestCard() : MissionCard("測試卡", "踩到任務的人多500元其他扣50自己房子全數升級")
{
}

void TestCard::show(People* ptr1, People** ptr2 , House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 500); // 加自己500
	for (int i = 0; i < 4; i++) { // 除了自己以外大家扣50
		if (ptr2[i]->getId() == ptr1->getId())continue;
		ptr2[i]->setCash(ptr2[i]->getCash() - 50);
	}
	for (int i = 0; i < 32; i++) { // 所有自己的房子被多蓋一層, 不用花錢
		if (ptr3[i]) { // 是房屋格
			if (ptr3[i]->getOwner() == ptr1) { // owner 是自己
				int maxhousenum = ptr3[i]->getHouseNum() + 1 > 4 ? 4 : ptr3[i]->getHouseNum() + 1; // 最大就4
				ptr3[i]->setHouseNum(maxhousenum);
			}
		}
	}
}