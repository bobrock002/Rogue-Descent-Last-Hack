
#include "Level.h"
#include <fstream>
#include <cstdio>
#include <iostream>



Level::Level()
{
}

void Level::load(string fileName, Player &player)
{
	//loads the level
	ifstream file;

	file.open(fileName);
	if (file.fail()) 
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line)) 
	{
		_levelData.push_back(line);
	}
	 
	file.close();

	// process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++)
		for (int j = 0; j < _levelData[i].size(); j++) 
		{
			tile = _levelData[i][j];

			switch (tile)
			{      
			case '@': // Player
				player.set_Position(j, i);
				break;
			case 'a': // acolyte
				_enemies.push_back(Enemy("acolyte",	tile, 'i', 'P', 1, 100, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'b': // beholder
				_enemies.push_back(Enemy("beholder", tile, 'w', 'S', 9, 100, 50, 50, 50, 50, 50, 50, 50, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'c': // cambion
				_enemies.push_back(Enemy("cambion",	tile, 'f', 'S', 5, 100, 50, 0, 50, 0, 30, 30, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'd': // darkling
				_enemies.push_back(Enemy("darkling", tile, 'c', 'M', 2, 100, 0, 0, 0, 0, 100, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'e': // ettercap
				_enemies.push_back(Enemy("ettercap", tile, 's', 'E', 2, 100, 0, 0, 0, 100, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'f': // flame devil
				_enemies.push_back(Enemy("flame devil", tile, 'b', 'F', 6, 100, 100, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'g': // goblin
				_enemies.push_back(Enemy("goblin", tile, 'd', 'S', 1, 100, 0, 0, 0, 0, 0, 0, 50, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'h': // hell hound
				_enemies.push_back(Enemy("hell hound", tile, 's', 'F', 3, 100, 50, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'i': // inmate
				_enemies.push_back(Enemy("inmate", tile, 'd', 'B', 1, 100, 0, 0, 0, 0, 0, 0, 0, 0 ));
				_enemies.back().setPosition(j, i);
				break;
			case 'j': // jelly
				_enemies.push_back(Enemy("gelatinous evil",	tile, 'm', 'M', 4, 1000, 50, 0, 0, 50, 100, 50, 50, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'k': // kobold
				_enemies.push_back(Enemy("kobold", tile, 'c', 'P', 1, 100, 0, 0, 0, 0, 0, 50, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'l': // lich
				_enemies.push_back(Enemy("lich", tile, 'w', 'M', 9, 200, 50, 50, 50, 50, 50, 50, 50, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'm': // madman
				_enemies.push_back(Enemy("madman", tile, 'r', 'P', 2, 100, 0, 0, 0, 0, 0, 0, 50, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'n': // necromancer
				_enemies.push_back(Enemy("necromancer", tile, 'w', 'E', 7, 100, 0, 0, 0, 50, 50, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'o': // ogre
				_enemies.push_back(Enemy("ogre", tile, 's', 'B', 3, 200, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'p': // polar demon
				_enemies.push_back(Enemy("polar demon",	tile, 'P', 'I', 8, 400, 50, 0, 100, 0, 0, 50, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'q': // quasit
				_enemies.push_back(Enemy("quasit", tile, 'i', 'L', 2, 100, 100, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'r': // revenant
				_enemies.push_back(Enemy("revenant", tile, 'f', 'B', 5, 0, 0, 0, 50, 0, 0, 0, 50, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 's': // skeleton
				_enemies.push_back(Enemy("skeleton", tile, 'd', 'B', 1, 0, 0, 0, 0, 0, 0, 0, 0, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 't': // thief
				_enemies.push_back(Enemy("thief", tile, 'r', 'P', 2, 100, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'u': // umber hulk
				_enemies.push_back(Enemy("umber hulk", tile, 'f', 'S', 8, 300, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'v': // vampire
				_enemies.push_back(Enemy("vampire", tile, 'w', 'P', 6, 0, 0, 0,  50, 50, 0, 50, 50, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'w': // warden
				_enemies.push_back(Enemy("warden", tile, 'm', 'S', 1, 100, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'x': // xorn
				_enemies.push_back(Enemy("xorn", tile, 'b', 'E', 7, 200, 0, 0, 0, 0, 0, 0, 0, 100));
				_enemies.back().setPosition(j, i);
				break;
			case 'y': // yeti
				_enemies.push_back(Enemy("yeti", tile, 'c', 'S', 4, 100, 0, 0, 100, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'z': // zombie
				_enemies.push_back(Enemy("zombie", tile, 's', 'B', 2, 0, 0, 0, 0, 0, 0, 0, 50, 0));
				_enemies.back().setPosition(j, i);
				break;
			case '[': // leather armor
				_items.push_back(Item("leather armor", tile, 10, 0, 0, 0, 0, 0, 2, 0, 10, 10, 10, 10, 0, 10, 0, 10, 0, 0, 0, 0, 0));
				_items.back().setPosition(j, i);
				break;
			case ']': // studded leather armor
				_items.push_back(Item("studded leather armor", tile, 15, 0, 0, 0, 0, 0, 3, 0, 10, 10, 10, 10, 0, 15, 0, 10, 0, 0, 0, 0, 0));
				_items.back().setPosition(j, i);
			case '{': // chain mail
				_items.push_back(Item("chain mail", tile, 20, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 30, 0, 20, 0, 0, 0, 0, 0));
				_items.back().setPosition(j, i);
			case '}': // scale mail
				_items.push_back(Item("scale mail", tile, 30, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 35, 10, 25, 0, 0, 0, 0, 0));
				_items.back().setPosition(j, i);
			case '(': // splint mail
				_items.push_back(Item("splint mail", tile, 40, 0, 0, 0, 0, 0, 6, 0, 15, 0, 10, 0, 0, 40, 20, 25, 0, 0, 0, 0, 0));
				_items.back().setPosition(j, i);
			case ')': // plate mail
				_items.push_back(Item("plate mail", tile, 50, 0, 0, 0, 0, 0, 7, 0, 20, 20, 20, 20, 0, 50, 25, 25, 0, 0, 0, 0, 0));
				_items.back().setPosition(j, i);
			case '|': // sharpened broom handle
				_items.push_back(Item("broom handle spear", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 'P'));
				_items.back().setPosition(j, i);
			case '/': // sword
				_items.push_back(Item("long sword", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 'S'));
				_items.back().setPosition(j, i);
			case '-': // shank
				_items.push_back(Item("shank", tile, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 'P'));
				_items.back().setPosition(j, i);
			case '+': // morning star
				_items.push_back(Item("morning star", tile, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 'B'));
				_items.back().setPosition(j, i);
			case '&': // whip
				_items.push_back(Item("whip", tile, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 'S'));
				_items.back().setPosition(j, i);
			case '%': // flail
				_items.push_back(Item("flail", tile, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1, 'B'));
				_items.back().setPosition(j, i);
			case '*': // brass knuckles
				_items.push_back(Item("spear", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 'B'));
				_items.back().setPosition(j, i);
			case '!': // club
				_items.push_back(Item("spear", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 'B'));
				_items.back().setPosition(j, i);
			case '$': // greatsword
				_items.push_back(Item("great sword", tile, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1, 'S'));
				_items.back().setPosition(j, i);
			case '_': // short sword
				_items.push_back(Item("short sword", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 'S'));
				_items.back().setPosition(j, i);
			case '"': // gold fronts
				_items.push_back(Item("gold fronts", tile, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 'P'));
				_items.back().setPosition(j, i);
			case '~': // iron spear
				_items.push_back(Item("cell bar spear", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 'P'));
				_items.back().setPosition(j, i);
			}
		}
}

void Level::print()
{
	system("CLS");

	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s", _levelData[i].c_str());
	}

}

void Level::movePlayer(char input, Player &player) 
{
	int playerX;
	int playerY;
	player.get_Position(playerX, playerY);
	
	switch (input) 
	{
	case 'w'://up
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 'a'://left
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 's'://down
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'd'://right
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("INVALID INPUT\n");
		system("PAUSE");
	}
}

void Level::updateEnemies(Player &player)
{
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;


	player.get_Position(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++)
	{
		aiMove = _enemies[i].getMove(playerX, playerY);
		_enemies[i].getPosition(enemyX, enemyY);


		switch (aiMove)
		{
		case 'w'://up
			processEnemyMove(player, i, enemyX, enemyY - 1);
			break;
		case 'a'://left
			processEnemyMove(player, i, enemyX - 1, enemyY);
			break;
		case 's'://down
			processEnemyMove(player, i, enemyX, enemyY + 1);
			break;
		case 'd'://right
			processEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		}
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

int Level::getLevel() 
{
	return _dungeonLevel;
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::setLevel(int level)
{
	_dungeonLevel = level;
}

void Level::processPlayerMove(Player &player, int targetX, int targetY) 
{
	int playerX;
	int playerY;
	player.get_Position(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case'.':
		player.set_Position(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
	
		break;
	}
}

void Level::processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY)
{
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;
	
	_enemies[enemyIndex].getPosition(enemyX, enemyY);

	player.get_Position(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case'.':
		_enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, _enemies[enemyIndex].getTile());
		break;
	case '@':
		monsterAttack(player, enemyX, enemyY);
		break;
	default:
		break;
	}
}

void Level::monsterAttack(Player &player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int damageRoll;
	int attackResult;
	int playerType;
	char attackType;
	string enemyName;
	string playerName;

	player.get_Position(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();
		playerName = player.get_name();

		if (targetX == enemyX && targetY == enemyY) {

			// Enemy Turn
			attackRoll = _enemies[i].attack();
			damageRoll = _enemies[i].damage();
			attackType = _enemies[i].get_dmgType();
			attackResult = player.takeDamage(attackRoll, damageRoll, attackType);

			if (attackResult != 0)
			{
				setTile(playerX, playerY, 'x');
				print();
				printf("%s was mercilessly slain by the %s.\n", playerName.c_str(), enemyName.c_str());
				system("PAUSE");

				exit(0);
				return;
			}

			return;
		}
	}
}
void Level::battleMonster(Player &player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int damageRoll;
	int attackResult;
	int playerType;
	char attackType;
	string enemyName;
	string playerName;

	player.get_Position(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();
		playerName = player.get_name();

		if (targetX == enemyX && targetY == enemyY) {

			// Attack!
			attackRoll = player.attack();
			damageRoll = player.damage();
			attackType = player.get_dmgType();
			playerType = player.get_playerType();
			printf("%s attacked the %s with a roll of %d, a damage roll of %d, and damage type %c.", playerName.c_str(), enemyName.c_str(), attackRoll, damageRoll, attackType);
			attackResult = _enemies[i].takeDamage(attackRoll, damageRoll, attackType);
			
			if (attackResult != 0)
			{
				setTile(targetX, targetY, '.');
				print();
				printf("%s has slain the %s!\n", playerName.c_str(), enemyName.c_str());
				// remove enemy
				_enemies[i] = _enemies.back();
				_enemies.pop_back();
				i--;

				
				system("PAUSE");
				player.add_Exp(attackResult, playerType);

				return;
			}
			
			// Enemy Turn
			attackRoll = _enemies[i].attack();
			damageRoll = _enemies[i].damage();
			attackType = _enemies[i].get_dmgType();
			attackResult = player.takeDamage(attackRoll, damageRoll, attackType);

			if (attackResult != 0)
			{
				setTile(playerX, playerY, 'x');
				print();
				printf("%s was mercilessly slain by the %s.\n", playerName.c_str(), enemyName.c_str());
				system("PAUSE");
				
				exit(0);
				return;
			}
			
			
			return;
		}
	}
}