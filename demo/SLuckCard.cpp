#include"SLuckCard.h"
SLuckCard::SLuckCard() : MissionCard("�W���B�d", "�����Ȫ��H�h1000���B�ۤv�Фl���Ƥɯ�")
{
    
}

void SLuckCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 1000); // �[�ۤv500
	for (int i = 0; i < 32; i++) { // �Ҧ��ۤv���Фl�Q�h�\�@�h, ���Ϊ��
		if (ptr3[i]) { // �O�Ыή�
			if (ptr3[i]->getOwner() == ptr1) { // owner �O�ۤv
				int maxhousenum = ptr3[i]->getHouseNum() + 1 > 4 ? 4 : ptr3[i]->getHouseNum() + 1; // �̤j�N4
				ptr3[i]->setHouseNum(maxhousenum);
			}
		}
	}
}
