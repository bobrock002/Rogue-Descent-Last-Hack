
#include "Enemy.h"
#include <ctime>
#include <random>

using namespace std;

Enemy::Enemy(
	string name, 
	char tile,
	char enemyType,
	char dmgType,
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
    )
{
	_name = name;
	_tile = tile;
	_level = level;
	_enemyType = enemyType;
	switch (enemyType)
	{
	case 's': //strong man
		_baseStr = (5 + (level * 2));
		_baseDex = (5 + (level * 1));
		_baseCon = (5 + (level * 1));
		_baseInt = (5 + (level * 1));
		_primaryStat = _baseStr;
		break;
	case 'd': //dodger
		_baseStr = (5 + (level * 1));
		_baseDex = (5 + (level * 2));
		_baseCon = (5 + (level * 1));
		_baseInt = (5 + (level * 1));
		_primaryStat = _baseDex;
		break;
	case 'c': //healthy
		_baseStr = (5 + (level * 1));
		_baseDex = (5 + (level * 1));
		_baseCon = (5 + (level * 2));
		_baseInt = (5 + (level * 1));
		_primaryStat = _baseStr;
		break;
	case 'i': //intellectual
		_baseStr = (5 + (level * 1));
		_baseDex = (5 + (level * 1));
		_baseCon = (5 + (level * 1));
		_baseInt = (5 + (level * 2));
		_primaryStat = _baseInt;
		break;
	case 'b': //berserker
		_baseStr = (5 + (level * 2));
		_baseDex = (5 + (level * 2));
		_baseCon = (5 + (level * 1));
		_baseInt = (5 + (level * 1));
		_primaryStat = _baseStr;
		break;
	case 'f': //fighter
		_baseStr = (5 + (level * 2));
		_baseDex = (5 + (level * 1));
		_baseCon = (5 + (level * 2));
		_baseInt = (5 + (level * 1));
		_primaryStat = _baseStr;
		break;
	case 'p': //paragon
		_baseStr = (5 + (level * 2));
		_baseDex = (5 + (level * 1));
		_baseCon = (5 + (level * 1));
		_baseInt = (5 + (level * 2));
		_primaryStat = _baseInt;
		break;
	case 'm': //monk
		_baseStr = (5 + (level * 1));
		_baseDex = (5 + (level * 2));
		_baseCon = (5 + (level * 2));
		_baseInt = (5 + (level * 1));
		_primaryStat = _baseDex;
		break;
	case 'r': //rogue
		_baseStr = (5 + (level * 1));
		_baseDex = (5 + (level * 2));
		_baseCon = (5 + (level * 1));
		_baseInt = (5 + (level * 2));
		_primaryStat = _baseDex;
		break;
	case 'w': //wizard
		_baseStr = (5 + (level * 1));
		_baseDex = (5 + (level * 1));
		_baseCon = (5 + (level * 2));
		_baseInt = (5 + (level * 2));
		_primaryStat = _baseInt;
		break;
	} 
	
	// placeholder algo for experience value, may need tuning.
	_experience = level * level;
	_armor = ((_baseDex / 2) + 10);
	_food = food;
	_fireR = fireR;
	_lightningR = lightningR;
	_iceR = iceR;
	_earthR = earthR;
	_magicR = magicR;
	_slashR = slashR;
	_bludgeonR = bludgeonR;
	_pierceR = pierceR;

	_maxHealth = (((_baseCon/2)*level) + (level * 10 ));
	_currentHealth = _maxHealth;
	_maxAP = (((_baseInt/2) * level) + (level * 10));
	_currentAP = _maxAP;

	_dmgType = dmgType;
	

	_dmgBonus = (_baseStr / 2);
	_hitBonus = (_baseStr / 2);

	

	// The idea here is to create gradually increasing damage over levels. 
	// This is my baseline progression but the numbers can be tuned later if needed.


	switch (level)
	{
	case 1:
		_die = 1;
		_dice = 1;
		break;
	case 2:
		_die = 2;
		_dice = 1;
		break;
	case 3:
		_die = 3;
		_dice = 1;
		break;
	case 4:
		_die = 4;
		_dice = 1;
		break;
	case 5:
		_die = 6;
		_dice = 1;
		break;
	case 6:
		_die = 8;
		_dice = 1;
		break;
	case 7:
		_die = 10;
		_dice = 1;
		break;
	case 8:
		_die = 6;
		_dice = 2;
		break;
	case 9:
		_die = 8;
		_dice = 2;
		break;
	case 10:
		_die = 6;
		_dice = 3;
		break;
	case 11:
		_die = 8;
		_dice = 3;
		break;
	case 12:
		_die = 6;
		_dice = 4;
		break;
	case 13:
		_die = 8;
		_dice = 4;
		break;
	case 14:
		_die = 6;
		_dice = 6;
		break;
	case 15:
		_die = 8;
		_dice = 6;
		break;
	case 16:
		_die = 6;
		_dice = 8;
		break;
	case 17:
		_die = 8;
		_dice = 8;
		break;
	case 18:
		_die = 6;
		_dice = 12;
		break;
	case 19:
		_die = 8;
		_dice = 12;
		break;
	case 20:
		_die = 6;
		_dice = 16;
		break;
	}
}

int Enemy::attack() 
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(1, 20);
	int rollResult = ((attackRoll(randomEngine)) + (_primaryStat/2));
	return rollResult;
}

int Enemy::damage() 
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> damageRoll(1, _die);
	int dmg = 0;
	int total;
	for (int i = 0; i < _dice; i++)
	{
		dmg += damageRoll(randomEngine);
	}
	total = (dmg + (_primaryStat/2));
	return total;
}
// return 0 if dead, otherwise not take dmg

int Enemy::takeDamage(int attack, int damage, char dmgType) 
{
	// this sets the damage type of the player against the resistance of the enemy
	int resistance;
	switch (dmgType)
	{
	case 'B':
		resistance = _bludgeonR;
		break;
	case 'S':
		resistance = _slashR;
		break;
	case 'P':
		resistance = _pierceR;
		break;
	case 'I':
		resistance = _iceR;
		break;
	case 'F':
		resistance = _fireR;
		break;
	case 'E':
		resistance = _earthR;
		break;
	case 'L':
		resistance = _lightningR;
		break;
	case 'M':
		resistance = _magicR;
		break;
	}

	attack -= _armor;
	int dmgTotal = (damage - ((damage * resistance) / 100));
	if (attack > 0)
	{
		_currentHealth -= dmgTotal;
		if (dmgTotal > 0)
		{
			printf("%s takes %d damage!\n", _name.c_str(), dmgTotal);
			system("PAUSE");
		}
		
		if (_currentHealth <= 0)
		{
			return _experience;
		}
		
	}

	printf("The %s evades the attack!\n", _name.c_str());
	system("PAUSE");
	return 0;

}
// sets enemy position
void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;

}

// Gets the position of the enemy 
void Enemy::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

char Enemy::get_dmgType()
{
	return _dmgType;
}