#include"ChangePosCard.h"
ChangePosCard::ChangePosCard() : MissionCard("����d", "�P�U�@�쪱�a������m")
{
}

void ChangePosCard::show(People* ptr1, People** ptr2, int playerNum, House** ptr3) {
	int tmp=ptr1->getPos();
	for (int i = 0; i < playerNum; i++) 
    { 
		if (ptr2[i]->getId() == ptr1->getId())
		{
		    if(i = playerNum - 1){
                ptr1->setPos(ptr2[0]->getPos()) ;
		        ptr2[0]->setPos(tmp) ;
		        break;
		    }
		    else
		    {
		        ptr1->setPos(ptr2[i+1]->getPos()) ;
		        ptr2[i+1]->setPos(tmp);
		        break;
            }
        }
	}
}
