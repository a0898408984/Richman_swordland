#include"FortuneCard.h"
FortuneCard::FortuneCard() : MissionCard("幸運女神!!!!", "本人錢+1000且所有房子升一級,其他人錢+300")
{
}

void FortuneCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 1000); // ?[??v500
	for (int i = 0; i < playerNum; i++) { // ???F??v?H?~?j?a??50
		if (ptr2[i]->getId() == ptr1->getId())continue;
		ptr2[i]->setCash(ptr2[i]->getCash() + 300);
	}
	for (int i = 0; i < 32; i++) { // ?????v????l?Q?h?\?@?h, ??????
		if (ptr3[i]) { // ?O????
			if (ptr3[i]->getOwner() == ptr1) { // owner ?O??v
				int maxhousenum = ptr3[i]->getHouseNum() + 1 > 4 ? 4 : ptr3[i]->getHouseNum() + 1; // ??j?N4
				ptr3[i]->setHouseNum(maxhousenum);
			}
		}
	}
}
