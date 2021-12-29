#include"TestCard.h"
TestCard::TestCard() : MissionCard("���եd", "�����Ȫ��H�h500����L��50�ۤv�Фl���Ƥɯ�")
{
}

void TestCard::show(People* ptr1, People** ptr2 , House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 500); // �[�ۤv500
	for (int i = 0; i < 4; i++) { // ���F�ۤv�H�~�j�a��50
		if (ptr2[i]->getId() == ptr1->getId())continue;
		ptr2[i]->setCash(ptr2[i]->getCash() - 50);
	}
	for (int i = 0; i < 32; i++) { // �Ҧ��ۤv���Фl�Q�h�\�@�h, ���Ϊ��
		if (ptr3[i]) { // �O�Ыή�
			if (ptr3[i]->getOwner() == ptr1) { // owner �O�ۤv
				int maxhousenum = ptr3[i]->getHouseNum() + 1 > 4 ? 4 : ptr3[i]->getHouseNum() + 1; // �̤j�N4
				ptr3[i]->setHouseNum(maxhousenum);
			}
		}
	}
}