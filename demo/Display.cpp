#include"Display.h"
#include <thread>
#include <chrono>
#include<iomanip>
#include<iostream>
using namespace std;
Display::Display(Game* g, InputHandler* i)
{
	ptrGame = g;
	ptrInput = i;
}

Display::~Display()
{
}

void Display::display0() {
	system("cls");
	cout << "Round:";
	cout << setw(10) << ptrGame->round << endl;
	cout << setw(20) << "Name";
	cout << setw(20) << "Cash";
	cout << setw(20) << "Pos";
	cout << setw(20) << "Order";
	cout << endl;
	for (int i = 0; i < ptrGame->numOfPlayers; i++) {
		cout << setw(20) << ptrGame->ptrPeople[i]->getName();
		cout << setw(20) << ptrGame->ptrPeople[i]->getCash();
		cout << setw(20) << ptrGame->ptrPeople[i]->getPos();
		cout << setw(20) << ptrGame->ptrPeople[i]->getOrder();
		cout << endl;
		cout << setw(6) << "";
		for (int j = 0; j < 32; j++) {
			cout << setw(3) << j;
		}
		cout << endl;
		cout << setw(6) << "房屋: ";
		for (int j = 0; j < 32; j++) {
			if (ptrGame->ptrMap->mapHouse[j]) {
				if (ptrGame->ptrMap->mapHouse[j]->sameOwner(ptrGame->ptrPeople[i])) {
					cout << setw(3) << ptrGame->ptrMap->mapHouse[j]->getHouseNum();
				}
				else
					cout << setw(3) << "";
			}
			else
				cout << setw(3) << "";
		}
		cout << endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
}

void Display::display1() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "\t\trollDice:";
	cout << setw(10) << ptrGame->getDiceNow() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
}

void Display::display2(int from,int to) {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    從 " << from << " 到 " << to <<endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Display::display3() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    買下 " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getName() << " 花費 " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getLandPrice() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display4() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    蓋房子 " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getName() << " 花費 " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getLandPrice()*0.5 << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display5() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    路過 " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getName() << " 花費 " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getTolls() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display6() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   被傳送到不明的地方"<< endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display7() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who <<" 遇到任務: "<< ptrGame->ptrCards[ptrGame->usedCards]->getName() << "  效果:" << ptrGame->ptrCards[ptrGame->usedCards]->getDescription() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display8() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   加入血盟騎士團" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display9() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   加入微笑棺木" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display10() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   被關進監牢中" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display11(int housePos) {
	House* ptr = ptrGame->ptrMap->mapHouse[housePos];
	cout << "  因破產 ";
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   的房子被賣掉 for " << ptr->getSumOfPrice()*0.5 << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display12() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   仍在監牢中" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void Display::display13() {
	ptrGame->showRank();
	cout << "---------------------------------------------------\n\n";
	cout << "遊戲結束" << endl;
	for (int i = 0; i < 4; i++) {
		cout <<i + 1 << setw(20) << ptrGame->ptrPeople[i]->getName() << " 剩下 " << ptrGame->ptrPeople[i]->getCash() << endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100*1000));
}