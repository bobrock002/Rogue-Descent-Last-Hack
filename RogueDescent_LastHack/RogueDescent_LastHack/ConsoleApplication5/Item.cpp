#include "Item.h"


Item::Item()
{
	_x = 0;
	_y = 0;
}


void Item::init(bool inInv, int itemNumber, string iname, int iType, int iArmor, int idmgDie, 
	int idmgDice, int idmgType, int icrit, int iStr, int iDex, int iCon, int iInt, int ihealth, 
	int iAP, int iattackPower, int ispellPower, int ifireR, int ilightningR, int ifrostR, 
	int iearthR, int islashR, int ibludgeonR, int ipierceR, int iValue, int iWeight)
{
	_inInv = inInv;
	_itemNumber = itemNumber;
	_iname = iname;
	_iType = iType;
	_iArmor = iArmor;
	_idmgDie = idmgDie;
	_idmgDice = idmgDice;
	_idmgType = idmgType;
	_icrit = icrit;
	_iStr = iStr;
	_iDex = iDex;
	_iCon = iCon;
	_iInt = iInt;
	_ihealth = ihealth;
	_iAP = iAP;
	_iattackPower = iattackPower;
	_ispellPower = ispellPower;
	_ifireR = ifireR;
	_ilightningR = ilightningR;
	_ifrostR = ifrostR;
	_iearthR = iearthR;
	_islashR = islashR;
	_ibludgeonR = ibludgeonR;
	_ipierceR = ipierceR;
	_iValue = iValue;
	_iWeight = iWeight;
}

void Item::getStr(int itemNumber[5])
{

}