#include"FastCard.h"
FastCard::FastCard() : MissionCard("�ֳt�樫", "�e������I�e�@��")
{
}

void FastCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
    if(ptr1->getPos()==31)ptr1->setCash(ptr1->getCash() + PASSORIGIN  ) ;
    else ptr1->setPos(31);
}
