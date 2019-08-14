#pragma once
#include "pch.h"
#include <string>


using namespace std;

class Enemy
{
public:
	Enemy(string name,
		char tile,		// char		name			SDCI
		char enemyType,	// s	=	strongman		2111
						// d	=	dodger			1211
						// c	=	healthy			1121
						// i	=	intellectual	1112
						// b	=	berserker		2211
						// f	=	fighter			2121
						// p	=	paragon			2112
						// m	=	monk			1221
						// r	=	rogue			1212
						// w	=	wizard			1122

		char dmgType,	// char     type
						// B	=	Bludgeoning 
						// S	=	Slashing 
						// P	=	Piercing 
						// I	=	Ice 
						// F	=	Fire,
						// E	=	Earth,
						// L	=	Lightning,
						// M	=	Magic
		int level,
		int food,
		int fireR,
		int lightningR,
		int iceR,
		int earthR,
		int magicR,
		int slashR,
		int bludgeonR,
		int pierceR

	);

	int attack();
	int damage();
	int takeDamage(int attack, int damage, char dmgType);

	// Setters

	void setPosition(int x, int y);

	// Getters

	void getPosition(int &x, int &y);
	char get_dmgType();
	string getName() { return _name; }
	char getTile() { return _tile; }

	//Movement

	char getMove(int playerX, int playerY);


private:

	// Properties
	// base stats
	string _name;
	char _tile;
	int _level;

	int _baseStr;
	int _baseDex;
	int _baseCon;
	int _baseInt;

	// modified (current) stats

	int _experience;
	int _armor; //Dex/2 + item bonuses
	int _food;

	// magic/elemental resistances
	int _fireR;
	int _lightningR;
	int _iceR;
	int _earthR;
	int _magicR;

	// physical resistances

	int _slashR;
	int _bludgeonR;
	int _pierceR;

	int _currentHealth; // = maxHealth to begin
	int _maxHealth; //  ((CON / 2) * Level) + (10 * Level))
	int _currentAP; // = maxAP to begin
	int _maxAP; // ((Int / 2) * Level) + (10 * Level)

	char _dmgType;
	int _die;
	int _dice;
	int _dmgBonus;
	int _hitBonus;

	char _enemyType;

	int _primaryStat;

	// Position


	int _x;
	int _y;
};