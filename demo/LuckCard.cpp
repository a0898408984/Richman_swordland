#include"LuckCard.h"
LuckCard::LuckCard() : MissionCard("���B�d", "�����Ȫ��H�h500��")
{
}

void LuckCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	ptr1->setCash(ptr1->getCash() + 500); // �[�ۤv500
	
}
