#include"JinxCard.h"
JinxCard::JinxCard() : MissionCard("�˷���", "�����H�Фl���Ŵ�@")
{
}

void JinxCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	
	for (int i = 0; i < 32; i++) { // �Ҧ��ۤv���Фl�Q�h�\�@�h, ���Ϊ��
		if (ptr3[i]) { // �O�Ыή�
		    for(int j = 0; j < playerNum; j++)
		    {
				if (ptr3[i]->getOwner() == ptr2[j]) { // ��owner 
					int maxhousenum = ptr3[i]->getHouseNum() - 1 < 0 ? 0 : ptr3[i]->getHouseNum() - 1; // �̤p��0 
					ptr3[i]->setHouseNum(maxhousenum);
					break;
				}
            }
		}
	}
}
