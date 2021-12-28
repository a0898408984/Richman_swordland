#pragma once
#include"HouseBeta.h"
class Map {
	//0:房屋格 1: 起點 2 傳送水晶: 3:mission_card 4:公會 5: 特殊建物格 6:監獄 7:
public:
    House** mapHouse;
    Map(){
        mapHouse = new House * [32];
    	for(int i =0 ;i<32 ; i++){

    		mapHouse[i] = NULL;
		}
    	mapHouse[1] = new House1();
        mapHouse[2] = new House2();
        mapHouse[4] = new House4();
        mapHouse[7] = new House7();
        mapHouse[8] = new House8();
        mapHouse[10] = new House10();
        mapHouse[12] = new House12();
        mapHouse[13] = new House13();
        mapHouse[15] = new House15();
        mapHouse[17] = new House17();
        mapHouse[18] = new House18();
        mapHouse[19] = new House19();
        mapHouse[20] = new House20();
        mapHouse[23] = new House23();
        mapHouse[25] = new House25();
        mapHouse[26] = new House26();
        mapHouse[28] = new House28();
        mapHouse[30] = new House30();
        mapHouse[31] = new House31();   
    }
    int maptile(int pos) {
        if (pos != 0 && pos != 3   && pos != 5 && pos != 6 && pos != 9&& pos != 11&& pos != 14&&pos != 16&& pos != 21&& pos != 22&& pos !=24 &&  pos != 27&& pos != 29 ) {
            return 0;
        }
        else if (pos == 3 ||  pos == 9  || pos == 14  || pos == 24  || pos == 29 ) {
            return 3;
        }
        else {
            switch (pos)
            {
            	case 0:
            		return 1;
            	case 5:
            		return 5;
            	case 6:
            		return 5;
            	case 11:
            		return 6;
            	case 16:
            		return 2;
            	case 21:
            		return 4;
            	case 22:
            		return 4;
            	case 27:
            		return 7;
            default:
                break;
            }
        }
        return 7;
    }
}; 
