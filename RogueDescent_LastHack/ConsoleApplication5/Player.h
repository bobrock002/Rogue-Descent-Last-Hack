#pragma once
#include <string>
#include <vector>
#include <random>

using namespace std;

class Player
{
public:
	Player();
	void init(
		string name,
		char playerType, //sets the character class
		// char			rap sheet		SDCI
		// 	H	=		Hitman			2211
		// 	E	=		Enforcer		2121
		// 	C	=		Crime Boss		2112
		// 	P	=		Pickpocket		1221
		// 	B	=		Burglar			1212
		// 	S	=		Smuggler		1122

		int level,
		int baseStr,
		int baseDex,
		int baseCon,
		int baseInt
		);
		
	int attack();
	int damage();

	// Setters for everything.
	
	void set_Position(int x, int y);
	void set_dmgType(char dmgType);
	void set_name(string name);
	void set_Level(int level);
	void set_Str(int Str);
	void set_Dex(int Dex);
	void set_Con(int Con);
	void set_Int(int Int);
	void set_MainStat(int mainStat);
	void set_Crit(int crit);
	void set_Experience(int experience);
	void set_Armor(int armor);
	void set_Capacity(int capacity);
	void set_Food(int food);
	void set_Luck(int luck);
	void set_FireR(int fireR);
	void set_LightningR(int lightningR);
	void set_IceR(int iceR);
	void set_EarthR(int earthR);
	void set_BludgeonR(int bludgeonR);
	void set_SlashR(int slashR);
	void set_PierceR(int pierceR);
	void set_CurrentHealth(int currentHealth);
	void set_MaxHealth(int maxHealth);
	void set_CurrentAP(int currentAP);
	void set_MaxAP(int MaxAP);
	void set_AttackPower(int attackPower);
	void set_AttackMod(int attackMod);
	void set_Die(int die);
	void set_Dice(int dice);
	void set_DmgType(char dmgType);

	//Adders for everything.

	void add_Exp(int experience, char playerType);
	void add_Str(int amount);
	void add_Dex(int amount);
	void add_Con(int amount);
	void add_Int(int amount);


	// Getters for everything.

	void get_Position(int &x, int &y);

	char get_dmgType();

	char get_playerType();

	string get_name() { return _name; }

	int takeDamage(int attack, int damage, char dmgType);

private:
	// Properties

	// base stats

	string _name;
	char _playerType;
	int _level;

	int _baseStr;
	int _baseDex;
	int _baseCon;
	int _baseInt;

	// modified (current) stats

	int _Str; // baseStr plus item bonuses.
	int _Dex; // baseDex plus item bonuses.
	int _Con; // baseCon plus item bonuses.
	int _Int; // baseInt plus item bonuses.
	int _mainStat; // based on class.

	int _crit; // (Dex / 20) + items. 

	// general stats
	int _experience;
	int _armor; //Dex/2 + item bonuses
	int _capacity; // Str * 10
	int _food;
	int _luck;

	// magic/elemental resistances
	int _fireR; //base + items
	int _lightningR; //base + items
	int _iceR; // base + items
	int _earthR; //base + items
	int _magicR; //base + items
	// physical resistances
	int _slashR; // base + items
	int _bludgeonR; // base + items
	int _pierceR; // base + items

	int _currentHealth; // = maxHealth to begin
	int _maxHealth; //  ((CON / 2) * Level) + (10 * Level))
	int _currentAP; // = maxAP to begin
	int _maxAP; // ((Int / 2) * Level) + (10 * Level)

	// combat
	int _attackPower; // main stat / 2 + items.
	int _attackMod;   // main stat / 2 + items.
	int _die;
	int _dice;
	char _dmgType;

	// Position
	int _x;
	int _y;
};

