#include"TestCard.h"
TestCard::TestCard() : MissionCard("���եd", "���եd�ĪG")
{
}

void TestCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	for (int i = 0; i < 32; i++) { // �Ыζä��t 
		if (ptr3[i]) { // �O�Ыή�
			if (!ptr3[i]->getOwner()) { // �S��owner
				ptr3[i]->setOwner(ptr2[Dice::randomInt(0, playerNum-1)]);
				ptr3[i]->setHouseNum(Dice::randomInt(0, 4));
			}
		}
	}
	//ptr1->setCash(ptr1->getCash() + 500); // �[�ۤv500
	//for (int i = 0; i < playerNum; i++) { // ���F�ۤv�H�~�j�a��50
	//	if (ptr2[i]->getId() == ptr1->getId())continue;
	//	ptr2[i]->setCash(ptr2[i]->getCash() - 50);
	//}
	//for (int i = 0; i < 32; i++) { // �Ҧ��ۤv���Фl�Q�h�\�@�h, ���Ϊ��
	//	if (ptr3[i]) { // �O�Ыή�
	//		if (ptr3[i]->getOwner() == ptr1) { // owner �O�ۤv
	//			int maxhousenum = ptr3[i]->getHouseNum() + 1 > 4 ? 4 : ptr3[i]->getHouseNum() + 1; // �̤j�N4
	//			ptr3[i]->setHouseNum(maxhousenum);
	//		}
	//	}
	//}
}