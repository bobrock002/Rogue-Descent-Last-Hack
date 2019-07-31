#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item();
	void init(bool inInv, 
		int itemNumber, 
		string iname, 
		int iType, 
		int iArmor, 
		int idmgDie, 
		int idmgDice, 
		int idmgType, 
		int icrit,
		int iStr, 
		int iDex, 
		int iCon, 
		int iInt, 
		int ihealth, 
		int iAP, 
		int iattackPower, 
		int ispellPower, 
		int ifireR,
		int ilightningR, 
		int ifrostR, 
		int iearthR, 
		int islashR, 
		int ibludgeonR, 
		int ipierceR, 
		int iValue, 
		int iWeight);
	
	void itemGen(int itemNumber);

	void getStr(int itemNumber[5]);
	void getDex(int itemNumber[5]);
	void getCon(int itemNumber[5]);
	void getInt(int itemNumber[5]);
	void getcrit(int itemNumber[5]);
	void getArmor(int itemNumber[5]);
	void getdmgDie(int itemNumber);
	void getdmgDice(int itemNumber);
	void getdmgType(int itemNumber);


private:
	// item name, number, type and location.
	int _itemNumber;
	string _iname;
	int _iType;
	bool _inInv;

	// item stats

	int _iArmor;
	int _idmgDie;
	int _idmgDice;
	int _idmgType;
	int _icrit;
	int _iStr;
	int _iDex;
	int _iCon;
	int _iInt;
	int _ihealth;
	int _iAP;
	int _iattackPower;
	int _ispellPower;
	int _ifireR;
	int _ilightningR;
	int _ifrostR;
	int _iearthR;
	int _islashR;
	int _ibludgeonR;
	int _ipierceR;
	int _iValue;
	int _iWeight;

	// spawn location.
	int _x;
	int _y;
};

