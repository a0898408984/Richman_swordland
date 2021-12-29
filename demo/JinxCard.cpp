#include"JinxCard.h"
JinxCard::JinxCard() : MissionCard("倒楣鬼", "全部人房子等級減一")
{
}

void JinxCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	
	for (int i = 0; i < 32; i++) { // 所有自己的房子被多蓋一層, 不用花錢
		if (ptr3[i]) { // 是房屋格
		    for(int j = 0; j < playerNum; j++)
		    {
				if (ptr3[i]->getOwner() == ptr2[j]) { // 有owner 
					int maxhousenum = ptr3[i]->getHouseNum() - 1 < 0 ? 0 : ptr3[i]->getHouseNum() - 1; // 最小為0 
					ptr3[i]->setHouseNum(maxhousenum);
					break;
				}
            }
		}
	}
}
