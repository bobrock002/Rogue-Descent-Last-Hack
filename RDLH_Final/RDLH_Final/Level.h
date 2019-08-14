#pragma once
#include "pch.h"
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Items.h"
#include <time.h>



using namespace std;
class Level
{
public:
	Level();


	void load(string fileName, Player &player);
	void print();
	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);
	// get
	char getTile(int x, int y);
	int getLevel();
	// set
	void setTile(int x, int y, char tile);
	void setLevel(int level);
	void mapGen();
	void saveMap();
	

private:
	int _dungeonLevel;


	void processPlayerMove(Player &player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
	void monsterAttack(Player &player, int targetX, int targetY);
	vector <string> _levelData;
	vector <Enemy> _enemies;
	vector <Item> _items;
};

