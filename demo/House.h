#pragma once
#include<string>
#include"People.h"
#define PASSORIGIN 2000

class House
{
public:
	House(std::string, std::string, double,bool=1); // 名稱, 描述, 土地價, 能蓋房子
	~House();
	
	bool setOwner(People*);
	bool sameOwner(People*);
	People* getOwner();

	bool checkBuildHouse(People*);
	virtual double getTolls();
	void buildHouse(People*);

	std::string getName();
	std::string getDescription();
	double getLandPrice();
	int getHouseNum();
	bool get_buildhouse();
	double getSumOfPrice();

	void setName(std::string);   
	void setDescription(std::string);
	void setLandPrice(double);
	void setHouseNum(int);

	void sellToBank();

private:
	double landPrice;
	std::string description;
	std::string name;
	int houseNum;
	double houseCoe;
	bool _buildhouse;
	double sumOfPrice;
	People* owner;
};

