#include"Display.h"
#include <thread>
#include <chrono>
Display::Display(Game* g, InputHandler* i)
{
	ptrGame = g;
	ptrInput = i;
}

Display::~Display()
{
}

void Display::display0() {}
void Display::display1() {}
void Display::display2(int from, int to) {}
void Display::display3() {}
void Display::display4() {}
void Display::display5() {}
void Display::display6() {}
void Display::display7() {}
void Display::display8() {}
void Display::display9() {}
void Display::display10() {}
void Display::display11(int housePos) {}
void Display::display12() {}
void Display::display13() {}
