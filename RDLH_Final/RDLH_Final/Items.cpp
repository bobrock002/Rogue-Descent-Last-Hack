#include "pch.h"
#include "Items.h"



Item::Item(string name, char type, int weight, int Str, int Dex, int Con, int Int, int crit, int armor, int luck,
	int fire, int lightning, int ice, int earth, int magic, int slash, int bludgeon, int pierce,
	int attackpower, int attackmod, int die, int dice, char dmg)
{
	int _itemWeight = weight;
	int _itemSTR = Str;
	int _itemDex = Dex;
	int _itemCon = Con;
	int _itemInt = Int;
	int _itemCrit = crit;
	int _itemArmor = armor;
	int _itemLuck = luck;
	int _itemFire = fire;
	int _itemLightning = lightning;
	int _itemIce = ice;
	int _itemEarth = earth;
	int _itemMagic = magic;
	int _itemSlash = slash;
	int _itemBludgeon = bludgeon;
	int _itemPierce = pierce;
	int _itemAttackPower = attackpower;
	int _itemAttackMod = attackmod;
	int _itemDie = die;
	int _itemDice = dice;
	char _itemdmgType = dmg;
	char _itemType = type;
	string _itemName = name;
}

void Item::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Item::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}