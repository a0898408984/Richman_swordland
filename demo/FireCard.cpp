#include"FireCard.h"
FireCard::FireCard() : MissionCard("大火災", "所有房屋樓層減一")
{
}

void FireCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	
	for (int i = 0; i < 32; i++) { 
		if (ptr3[i]) { 
			if (ptr3[i]->getOwner() == ptr1) { 
				int maxhousenum = ptr3[i]->getHouseNum() - 1 < 0 ? 0 : ptr3[i]->getHouseNum() - 1; // ??j?N4
				ptr3[i]->setHouseNum(maxhousenum);
			}
		}
	}
}
