#include "Player.h"
#include <random>
#include <ctime>

using namespace std;
// Constructor, just initializes position to zero.

Player::Player() 
{
	_x = 0;
	_y = 0;
}

// Initializes player with properties

void Player::init(
	string name,
	char playerType,
	int level, 
	int baseStr, 
	int baseDex, 
	int baseCon, 
	int baseInt
	) 
{
	_name = name;
	_playerType = playerType;
	_level = level;

	_baseStr = baseStr;
	_baseDex = baseDex;
	_baseCon = baseCon;
	_baseInt = baseInt;

	_Str = baseStr;
	_Dex = baseDex;
	_Con = baseCon;
	_Int = baseInt;

	switch (playerType)
	{
	case 'H':
		_mainStat = baseStr;
		break;
	case 'E':
		_mainStat = baseStr;
		break;
	case 'C':
		_mainStat = baseInt;
		break;
	case 'P':
		_mainStat = baseDex;
		break;
	case 'B':
		_mainStat = baseDex;
		break;
	case 'S':
		_mainStat = baseInt;
	}

	_crit = ((_Dex / 20) + 1);
	_experience = 0;
	_armor = (_Dex / 2) + 10;
	_capacity = (_Str * 10);
	_food = 1000;
	_luck = 0;
	_attackPower = (_mainStat / 2);
	_attackMod = (_mainStat / 2);
	_fireR = 0;
	_lightningR = 0;
	_iceR = 0;
	_earthR = 0;
	_magicR = 0;
	_slashR = 0;
	_bludgeonR = 0;
	_pierceR = 0;
	_maxHealth = (((_Con / 2)*level) + (level * 10));
	_currentHealth = _maxHealth;
	_maxAP = (((_Int / 2)* level) + (level * 10));
	_currentAP = _maxAP;
	_die = 8;
	_dice = 1;
	_dmgType = 'B';

	printf("Level: %d \n", _level);
	printf("Name: %s \n", _name);
	printf("Str: %d \n", _Str);
	printf("Dex: %d \n", _Dex);
	printf("Con: %d \n", _Con);
	printf("Int: %d \n", _Int);
	printf("die: %d \n", _die);
	printf("dice: %d \n", _dice);
	printf("Health: %d \n", _currentHealth);
	
	system("PAUSE");

}

// Player attack function.

int Player::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(1, 20);
	int rollResult = (attackRoll(randomEngine));
	int attackResult = (rollResult + _attackMod);
	return attackResult;
}

// Player damage function.

int Player::damage() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> critCheck(1, 20);
	uniform_int_distribution<int> damageRoll(1, _die);

	int critResult = (critCheck(randomEngine));
	int critMult = 0;
	if (critResult = 20) 
	{
		int critMult = _crit;
	}
	else
	{
		int critMult = 1;
	}

	int dmg = 0;
	int total;
	int totalResult;
	for (int i = 0; i < _dice; i++)
	{
		dmg += damageRoll(randomEngine);
	}
	total = (dmg + _attackPower);
	totalResult = (total * critMult);
	return totalResult;
}

//Setters 

void Player::set_Position(int x, int y)
{
	_x = x;
	_y = y;

}

void Player::set_name(string name) 
{
	_name = name;
}

void Player::set_dmgType(char dmgType)
{
	_dmgType = dmgType;
}

void Player::set_Level(int level)
{
	_level = level;
}

void Player::set_Str(int Str) 
{
	_Str = Str;
}

void Player::set_Dex(int Dex)
{
	_Dex = Dex;
}

void Player::set_Con(int Con)
{
	_Con = Con;
}

void Player::set_Int(int Int)
{
	_Int = Int;
}

void Player::set_MainStat(int mainStat)
{
	_mainStat = mainStat;
}

void Player::set_Crit(int crit)
{
	_crit = crit;
}

void Player::set_Experience(int experience)
{
	_experience = experience;
}

void Player::set_Armor(int armor)
{
	_armor = armor;
}

void Player::set_Capacity(int capacity)
{
	_capacity = capacity;
}

void Player::set_Food(int food)
{
	_food = food;
}

void Player::set_Luck(int luck)
{
	_luck = luck;
}

void Player::set_FireR(int fireR)
{
	_fireR = fireR;
}

void Player::set_LightningR(int lightningR)
{
	_lightningR = lightningR;
}

void Player::set_IceR(int iceR)
{
	_iceR = iceR;
}

void Player::set_EarthR(int earthR)
{
	_earthR = earthR;
}

void Player::set_BludgeonR(int bludgeonR)
{
	_bludgeonR = bludgeonR;
}

void Player::set_SlashR(int slashR)
{
	_slashR = slashR;
}

void Player::set_PierceR(int pierceR)
{
	_pierceR = pierceR;
}

void Player::set_CurrentHealth(int currentHealth)
{
	_currentHealth = currentHealth;
}

void Player::set_MaxHealth(int maxHealth)
{
	_maxHealth = maxHealth;
}

void Player::set_CurrentAP(int currentAP)
{
	_currentAP = currentAP;
}

void Player::set_MaxAP(int maxAP)
{
	_maxAP = maxAP;
}

void Player::set_AttackPower(int attackPower)
{
	_attackPower = attackPower;
}

void Player::set_AttackMod(int attackMod)
{
	_attackMod = attackMod;
}

void Player::set_Die(int die)
{
	_die = die;
}

void Player::set_Dice(int dice)
{
	_dice = dice;
}

void Player::set_DmgType(char dmgType)
{
	_dmgType = dmgType;
}

// Adders

void Player::add_Exp(int experience, char playerType)
{
	_experience += experience;
	int threshold = ((_level * _level) * 100);
	while (_experience > threshold)
	{
		printf("You have become more powerful!\n");
		_experience -= threshold;
		switch (playerType)
		{
		case 'H':
			_Str += 2;
			_Dex += 2;
			_Con += 1;
			_Int += 1;
			break;
		case 'E':
			_Str += 2;
			_Dex += 1;
			_Con += 2;
			_Int += 1;
			break;
		case 'C':
			_Str += 2;
			_Dex += 1;
			_Con += 1;
			_Int += 2;
			break;
		case 'P':
			_Str += 1;
			_Dex += 2;
			_Con += 2;
			_Int += 1;
			break;
		case 'B':
			_Str += 1;
			_Dex += 2;
			_Con += 1;
			_Int += 2;
			break;
		case 'S':
			_Str += 1;
			_Dex += 1;
			_Con += 2;
			_Int += 2;
			break;
		}

		switch (_playerType)
		{
		case 'H':
			_mainStat = _Str;
			break;
		case 'E':
			_mainStat = _Str;
			break;
		case 'C':
			_mainStat = _Int;
			break;
		case 'P':
			_mainStat = _Dex;
			break;
		case 'B':
			_mainStat = _Dex;
			break;
		case 'S':
			_mainStat = _Int;
		}

		_maxHealth += ((_Con / 2) + 10);
		_currentHealth = _maxHealth;
		_maxAP += ((_Int / 2) + 10);
		_currentAP = _maxAP;
		_level++;
		system("PAUSE");
	}
}

void Player::add_Str(int amount) 
{
	_Str += amount;
}
void Player::add_Dex(int amount)
{
	_Dex += amount;
}
void Player::add_Con(int amount)
{
	_Con += amount;
}
void Player::add_Int(int amount)
{
	_Int += amount;
}


// Getters

void Player::get_Position(int &x, int &y)
{
	x = _x;
	y = _y;
}

char Player::get_dmgType()
{
	return _dmgType;
}

char Player::get_playerType()
{
	return _playerType;
}

int Player::takeDamage(int attack, int damage, char dmgType)
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
	if (attack > 0)
	{
		int dmgTotal = (damage - ((damage * resistance) / 100));
		_currentHealth -= dmgTotal;
		if (dmgTotal > 0)
		{
			printf("You are wounded for %d damage.\n", dmgTotal);
			system("PAUSE");
		}

		if (_currentHealth <= 0)
		{
			return 1;
		}
		
	}
	printf("You evade the attack!\n", _name.c_str());
	system("PAUSE");
	return 0;

}