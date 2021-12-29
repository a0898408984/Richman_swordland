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
		cout << setw(6) << "�Ы�: ";
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
	cout << "    �q " << from << " �� " << to <<endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Display::display3() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    �R�U " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getName() << " ��O " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getLandPrice() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display4() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    �\�Фl " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getName() << " ��O " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getLandPrice()*0.5 << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display5() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "    ���L " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getName() << " ��O " << ptrGame->ptrMap->mapHouse[ptrGame->ptrPeople[ptrGame->who]->getPos()]->getTolls() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display6() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   �Q�ǰe�줣�����a��"<< endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display7() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who <<" �J�����: "<< ptrGame->ptrCards[ptrGame->usedCards]->getName() << "  �ĪG:" << ptrGame->ptrCards[ptrGame->usedCards]->getDescription() << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display8() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   �[�J����M�h��" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display9() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   �[�J�L���ä�" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display10() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   �Q���i�ʨc��" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display11(int housePos) {
	House* ptr = ptrGame->ptrMap->mapHouse[housePos];
	cout << "  �]�}�� ";
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   ���Фl�Q�汼 for " << ptr->getSumOfPrice()*0.5 << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Display::display12() {
	cout << ptrGame->ptrPeople[ptrGame->who]->getName() << ptrGame->who;
	cout << "   ���b�ʨc��" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void Display::display13() {
	ptrGame->showRank();
	cout << "---------------------------------------------------\n\n";
	cout << "�C������" << endl;
	for (int i = 0; i < 4; i++) {
		cout <<i + 1 << setw(20) << ptrGame->ptrPeople[i]->getName() << " �ѤU " << ptrGame->ptrPeople[i]->getCash() << endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100*1000));
}