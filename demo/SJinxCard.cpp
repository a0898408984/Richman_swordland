#include"SJinxCard.h"
SJinxCard::SJinxCard() : MissionCard("超級倒楣鬼", "全部人房子等級降一且扣300元")
{
}

void SJinxCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	 // 加自己500
	for (int i = 0; i < playerNum; i++) { // 除了自己以外大家扣50
		ptr2[i]->setCash(ptr2[i]->getCash() - 300);
	}
	for (int i = 0; i < 32; i++) { // 所有自己的房子被多蓋一層, 不用花錢
		if (ptr3[i]) { // 是房屋格
		    for(int j = 0; j < playerNum; j++)
		    {
		        if (ptr3[i]->getOwner() == ptr2[j]) { // 有owner 
				int maxhousenum = ptr3[i]->getHouseNum() - 1 < 0 ? 0 : ptr3[i]->getHouseNum() - 1; // 最小為0 
				ptr3[i]->setHouseNum(maxhousenum);
			}
            }
		}
	}
}
