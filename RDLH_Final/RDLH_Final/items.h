#pragma once
#include "pch.h"
#include <string>

using namespace std;

class Item
{
public:
	Item(string name, char type, int weight, int Str, int Dex, int Con, int Int, int crit, int armor, int luck,
		int fire, int lightning, int ice, int earth, int magic, int slash, int bludgeon, int pierce,
		int attackpower, int attackmod, int die, int dice, char dmg);
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);

private:
	int _itemWeight;
	int _itemStr;
	int _itemDex;
	int _itemCon;
	int _itemInt;
	int _itemCrit;
	int _itemArmor;
	int _itemLuck;
	int _itemFire;
	int _itemLightning;
	int _itemIce;
	int _itemEarth;
	int _itemMagic;
	int _itemSlash;
	int _itemBludgeon;
	int _itemPierce;
	int _itemAttackPower;
	int _itemAttackMod;
	int _itemDie;
	int _itemDice;
	char _itemdmgType;
	char _itemType;
	string _itemName;
	int _x;
	int _y;
};
