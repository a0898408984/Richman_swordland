#include"House.h"

bool House::setOwner(People* who) {
	if (!owner) {
		owner = who;
		return true;
	}
	else
		return false;
}

void House::setLandPrice(double val) {
	landPrice = val;
}
void House::setDescription(std::string val) {
	description = val;
}
void House::setName(std::string val) {
	name = val;
}
void House::setHouseNum(int val) {
	houseNum = val;
}




bool House::sameOwner(People* who) {
	if (!owner)return false;
	if (who->getId() == owner->getId())
		return true;
	else
		return false;
}

bool House::checkBuildHouse(People* who) {
	if (!owner) {
		if (who->getCash() >= this->landPrice) {
			return true;
		}
		else {
			return false;
		}
	}
	if (!_buildhouse)return false;
	if (sameOwner(who)&& houseNum < 4) { 
		if (who->getCash() >= this->landPrice * 0.5) { 
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void House::buildHouse(People* who) {
	if (!owner) {
		if (who->getCash() >= this->landPrice) {
			this->owner = who;
			who->setCash(who->getCash() - this->landPrice);
			sumOfPrice += this->landPrice;
			return ;
		}
		else {
			return ;
		}
	}
	if (!_buildhouse)return ;
	if (sameOwner(who) && houseNum < 4) {
		if (who->getCash() >= this->landPrice * 0.5) {
			who->setCash(who->getCash() - this->landPrice * 0.5);
			houseNum++;
			sumOfPrice += this->landPrice * 0.5;
			return ;
		}
		else {
			return ;
		}
	}
	return ;
}



double House::getSumOfPrice() {
	if (owner) {
		sumOfPrice = this->landPrice + this->landPrice * 0.5 * this->houseNum;
	}
	else {
		sumOfPrice = 0;
	}
	return sumOfPrice;
}
double House::getTolls() {
	if (!owner)return 0;
	return landPrice * (0.5 + (houseNum == 4?double(5):double(houseNum)) ) * (owner->getDoubleHousePrice() ? double(2) : double(1));
}
People* House::getOwner() {
	return owner;
}
std::string House::getDescription() {
	return description;
}
std::string House::getName() {
	return name;
}
double House::getLandPrice() {
	return landPrice;
}

int House::getHouseNum() {
	return houseNum;
}
bool House::get_buildhouse() {
	return _buildhouse;
}

void House::sellToBank() {
	houseNum = 0;
	sumOfPrice = 0;
	owner = NULL;
}


House::House(std::string n, std::string s, double lp, bool cb) {
	landPrice = lp;
	name = n;
	description = s;
	houseNum = 0;
	sumOfPrice = 0;
	_buildhouse = cb;
	owner = NULL;
}


House::~House() {}