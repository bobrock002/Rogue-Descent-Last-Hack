#include "pch.h"
#include "Player.h"
#include <random>
#include <ctime>
#include <cstdlib>

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
	int critMult = 1;
	if (critResult = 20)
	{
		int critMult = _crit;
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

// Print Player
void Player::printPlayer(Player &player)
{
	cout << player._name << " STR:" << player._Str << " DEX:" << player._Dex <<
		" CON:" << player._Con << " INT:" << player._Int << " HPMax:" << player._maxHealth <<
		" HP:" << player._currentHealth << endl;
}
//Save Player

void Player::savePlayer(Player &player)
{
	ofstream saveFile;
	saveFile.open("SavedGame.txt");
	saveFile << player._name << " " << player._playerType << " " << player._level << " " << player._baseStr << " " << player._baseDex
		<< " " << player._baseCon << " " << player._baseInt << " " << player._Str << " " << player._Dex << " " << player._Con
		<< " " << player._Int << " " << player._mainStat << " " << player._crit << " " << player._experience
		<< " " << player._armor << " " << player._capacity << " " << player._food << " " << player._luck << " " << player._fireR
		<< " " << player._lightningR << " " << player._iceR << " " << player._earthR << " " << player._magicR << " " << player._slashR << " " << player._bludgeonR
		<< " " << player._pierceR << " " << player._currentHealth << " " << player._maxHealth << " " << player._currentAP
		<< " " << player._maxAP << " " << player._attackPower << " " << player._attackMod << " " << player._die << " " << player._dice
		<< " " << player._dmgType << " " << player._x << " " << player._y << endl;
	saveFile.close();
}

// Load Player
void Player::loadPlayer(Player &player)
{
	string name;
	char playerType;
	int level, baseStr, baseDex, baseCon, baseInt, Str, Dex, Con, Int, mainStat, crit, experience, armor, capacity, food, luck, fireR,
		lightningR, iceR, earthR, magicR, slashR, bludgeonR, pierceR, currentHealth, maxHealth, currentAP, maxAP, attackPower,
		attackMod, die, dice, x, y;
	char dmgType;
	
	ifstream loadFile;
	loadFile.open("SavedGame.txt");
	// error check
	if (loadFile.fail())
	{
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	if (loadFile.is_open())
	{
		loadFile >> name >> playerType >> level >> baseStr >> baseDex >> baseCon >> baseInt >> Str >> Dex >> Con >> Int >> mainStat >>
			crit >> experience >> armor >> capacity >> food >> luck >> fireR >> lightningR >> iceR >> earthR >> magicR >> slashR >> bludgeonR >>
			pierceR >> currentHealth >> maxHealth >> currentAP >> maxAP >> attackPower >> attackMod >> die >> dice >> dmgType >> x >> y;

		player.set_name(name);
		player.set_playerType(playerType);
		player.set_Level(level);
		player.set_baseStr(baseStr);
		player.set_baseDex(baseDex);
		player.set_baseCon(baseCon);
		player.set_baseInt(baseInt);
		player.set_Str(Str);
		player.set_Dex(Dex);
		player.set_Con(Con);
		player.set_Int(Int);
		player.set_MainStat(mainStat);
		player.set_Crit(crit);
		player.set_Experience(experience);
		player.set_Armor(armor);
		player.set_Capacity(capacity);
		player.set_Food(food);
		player.set_Luck(luck);
		player.set_FireR(fireR);
		player.set_LightningR(lightningR);
		player.set_IceR(iceR);
		player.set_EarthR(earthR);
		player.set_MagicR(magicR);
		player.set_SlashR(slashR);
		player.set_BludgeonR(bludgeonR);
		player.set_PierceR(pierceR);
		player.set_CurrentHealth(currentHealth);
		player.set_MaxHealth(maxHealth);
		player.set_CurrentAP(currentAP);
		player.set_MaxAP(maxAP);
		player.set_AttackPower(attackPower);
		player.set_AttackMod(attackMod);
		player.set_Die(die);
		player.set_Dice(dice);
		player.set_DmgType(dmgType);
		player.set_Position(x, y);
	}
	loadFile.close();
}
//Setters 

void Player::set_MagicR(int magicR)
{
	_magicR = magicR;
}

void Player::set_playerType(char playerType)
{
	_playerType = playerType;
}

void Player::set_baseStr(int baseStr)
{
	_baseStr = baseStr;
}

void Player::set_baseDex(int baseDex)
{
	_baseDex = baseDex;
}

void Player::set_baseCon(int baseCon)
{
	_baseCon = baseCon;
}

void Player::set_baseInt(int baseInt)
{
	_baseInt = baseInt;
}

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
	int tempMain = _mainStat;
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
		_attackPower += (tempMain - _mainStat);
		_attackMod += (tempMain - _mainStat);
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

void Player::add_crit(int amount)
{
	_crit += amount;
}
void Player::add_armor(int amount)
{
	_armor += amount;
}
void Player::add_capacity(int amount)
{
	_capacity += amount;
}
void Player::add_food(int amount)
{
	_food += amount;
}
void Player::add_luck(int amount)
{
	_luck += amount;
}
void Player::add_fireR(int amount)
{
	_fireR += amount;
}
void Player::add_iceR(int amount)
{
	_iceR += amount;
}
void Player::add_lightningR(int amount)
{
	_lightningR += amount;
}
void Player::add_earthR(int amount)
{
	_earthR += amount;
}
void Player::add_magicR(int amount)
{
	_magicR += amount;
}
void Player::add_slashR(int amount)
{
	_slashR += amount;
}
void Player::add_bludgeonR(int amount)
{
	_bludgeonR += amount;
}
void Player::add_pierceR(int amount)
{
	_pierceR += amount;
}
void Player::add_currentHealth(int amount)
{
	_currentHealth += amount;
}
void Player::add_maxHealth(int amount)
{
	_maxHealth += amount;
}
void Player::add_currentAP(int amount)
{
	_currentAP += amount;
}
void Player::add_maxAP(int amount)
{
	_maxAP += amount;
}
void Player::add_attackPower(int amount)
{
	_attackPower += amount;
}
void Player::add_attackMod(int amount)
{
	_attackMod += amount;
}
void Player::add_die(int amount)
{
	_die += amount;
}
void Player::add_dice(int amount)
{
	_dice += amount;
}

// Getters

void Player::get_Position(int &x, int &y)
{
	x = _x;
	y = _y;
}

int Player::get_x()
{
	return _x;
}
int Player::get_y()
{
	return _y;
}

char Player::get_dmgType()
{
	return _dmgType;
}

char Player::get_playerType()
{
	return _playerType;
}

int Player::get_level()
{
	return _level;
}

string Player::get_name()
{
	return _name;
}

int Player::get_baseStr()
{
	return _baseStr;
}

int Player::get_baseDex()
{
	return _baseDex;
}

int Player::get_baseCon()
{
	return _baseCon;
}

int Player::get_baseInt()
{
	return _baseInt;
}

int Player::get_Str()
{
	return _Str;
}

int Player::get_Dex()
{
	return _Dex;
}

int Player::get_Con()
{
	return _Con;
}

int Player::get_Int()
{
	return _Int;
}

int Player::get_mainStat()
{
	return _mainStat;
}

int Player::get_crit()
{
	return _crit;
}

int Player::get_experience()
{
	return _experience;
}

int Player::get_armor()
{
	return _armor;
}

int Player::get_capacity()
{
	return _capacity;
}

int Player::get_food()
{
	return _food;
}

int Player::get_luck()
{
	return _luck;
}

int Player::get_fireR()
{
	return _fireR;
}

int Player::get_iceR()
{
	return _iceR;
}

int Player::get_lightningR()
{
	return _lightningR;
}

int Player::get_earthR()
{
	return _earthR;
}

int Player::get_magicR()
{
	return _magicR;
}

int Player::get_slashR()
{
	return _slashR;
}

int Player::get_bludgeonR()
{
	return _bludgeonR;
}

int Player::get_pierceR()
{
	return _pierceR;
}

int Player::get_currentHealth()
{
	return _currentHealth;
}

int Player::get_maxHealth()
{
	return _maxHealth;
}

int Player::get_currentAP()
{
	return _currentAP;
}

int Player::get_maxAP()
{
	return _maxAP;
}

int Player::get_attackPower()
{
	return _attackPower;
}

int Player::get_attackMod()
{
	return _attackMod;
}

int Player::get_die()
{
	return _die;
}

int Player::get_dice()
{
	return _dice;
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
			
		}

		if (_currentHealth <= 0)
		{
			return 1;
		}

	}
	else if (attack <= 0)
	{
		printf("You evade the attack!\n");
	}
	system("PAUSE");
	return 0;
}