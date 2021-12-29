#include"People.h"

People::People(std::string s, double cashmoney, double depositmoney)
{
	deposit = depositmoney;
	cash = cashmoney;
	name = s;
	doubleHousePrice = false;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		sum += int(s[i]);
	id = sum + Dice::randomInt(1, 100000);
	pos = 0;
	order = 0;
}

bool People::getDoubleHousePrice() {
	return doubleHousePrice;
}
void People::setDoubleHousePrice(bool doublePrice) {
	doubleHousePrice = doublePrice;
}

People::~People() {}
int People::getId() {
	return this->id;
}
int People::getPos() {
	return this->pos;
}
int People::getOrder() {
	return this->order;
}
double People::getCash() {
	return this->cash;
}
double People::getDeposit() {
	return this->deposit;
}
std::string People::getName() {
	return this->name;
}


void People::setCash(double num) {
	this->cash = num;
}
void People::setDeposit(double num) {
	this->deposit = num;
}
void People::setName(std::string s) {
	this->name = s;
}
void People::setPos(int num) {
	this->pos = num;
}
void People::setOrder(int num) {
	this->order = num;
}
int People::getDiceNum(Dice* &ptr) {
	return ptr->getDiceNum();
}

