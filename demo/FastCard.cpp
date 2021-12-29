#include"FastCard.h"
FastCard::FastCard() : MissionCard("快速行走", "前往到終點前一格")
{
}

void FastCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
    if(ptr1->getPos()==31)ptr1->setCash(ptr1->getCash() + PASSORIGIN  ) ;
    else ptr1->setPos(31);
}
