#include "pch.h"
#include "Level.h"
#include <fstream>
#include <cstdio>
#include <iostream>
#include <conio.h>



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
				_enemies.push_back(Enemy("acolyte", tile, 'i', 'P', 1, 100, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'b': // beholder
				_enemies.push_back(Enemy("beholder", tile, 'w', 'S', 9, 100, 50, 50, 50, 50, 50, 50, 50, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'c': // cambion
				_enemies.push_back(Enemy("cambion", tile, 'f', 'S', 5, 100, 50, 0, 50, 0, 30, 30, 0, 0));
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
				_enemies.push_back(Enemy("inmate", tile, 'd', 'B', 1, 100, 0, 0, 0, 0, 0, 0, 0, 0));
				_enemies.back().setPosition(j, i);
				break;
			case 'j': // jelly
				_enemies.push_back(Enemy("gelatinous evil", tile, 'm', 'M', 4, 1000, 50, 0, 0, 50, 100, 50, 50, 50));
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
				_enemies.push_back(Enemy("polar demon", tile, 'P', 'I', 8, 400, 50, 0, 100, 0, 0, 50, 0, 0));
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
				_enemies.push_back(Enemy("vampire", tile, 'w', 'P', 6, 0, 0, 0, 50, 50, 0, 50, 50, 50));
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
				_items.push_back(Item("club", tile, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 'B'));
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
	case 'g':
		player.savePlayer(player);
		saveMap();
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
	int dungeonLevel = getLevel();
	char input;

	switch (moveTile)
	{
	case'.':
		player.set_Position(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	case '<':
		player.set_Position(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');

		printf("A stairway is leading upwards. Press '<' to ascend.");
		input = _getch();
		if (input = '<')
		{
			dungeonLevel--;
			setLevel(dungeonLevel);
			mapGen();
			load("map.txt", player);
		}
		break;
	case '>':
		player.set_Position(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');

		printf("A stairway is leading downwards. Press '>' to descend.");
		input = _getch();
		if (input = '>')
		{
			dungeonLevel++;
			setLevel(dungeonLevel);
			mapGen();
			load("map.txt", player);
		}
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
	int exp;
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
			//attackRoll = _enemies[i].attack();
			//damageRoll = _enemies[i].damage();
			//attackType = _enemies[i].get_dmgType();
			//attackResult = player.takeDamage(attackRoll, damageRoll, attackType);

			//if (attackResult != 0)
			//{
			//	setTile(playerX, playerY, 'x');
			//	print();
			//	printf("%s was mercilessly slain by the %s.\n", playerName.c_str(), enemyName.c_str());
			//	system("PAUSE");
			//	exit(0);
			//	return;
			//}


			return;
		}
	}
}





void Level::mapGen()
{
	srand(time(NULL));

	//make map text file.
	std::ofstream map;
	map.open("map.txt");

	const int Length = 80;
	const int Height = 20;

	char Wall = '#';
	char Floor = '.';
	char Player = '@';
	char UpStairs = '<';
	char DownStairs = '>';

	char mapx[Length][Height];

	//Zero the map
	for (int j = 0; j < Height; j++) {
		for (int i = 0; i < Length; i++) {
			mapx[i][j] = Wall;
		}
	}


	//initial continent spawn points
	for (int j = 0; j < Height; j++) {
		for (int i = 0; i < Length; i++) {
			int x = rand() % 300;
			if (x < 4 && i>5 && i < Length - 5 && j>5 && j < Height - 5) {
				mapx[i][j] = '1';
			}
		}
	}


	//generate continents at spawn points
	for (int j = 0; j < Height; j++) {
		for (int i = 0; i < Length; i++) {
			if (mapx[i][j] == '1') {
				for (int a = i - 5; a <= i + 5; a++) {
					for (int b = j - 5; b <= j + 5; b++) {
						if (a == i && b == j) {
						}
						else {
							int x = rand() % 100;
							if (x > 50) {
								mapx[a][b] = Floor;
							}
						}
					}
				}
			}
		}
	}



	//Floor with wall points between two floor areas.

	for (int j = 0; j < Height; j++) {
		for (int i = 0; i < Length; i++) {
			//wall between two floor areas
			if (mapx[i][j] == Floor && mapx[i + 1][j] == Wall && mapx[i + 2][j] == Floor) {
				mapx[i + 1][j] = Floor;
			}
			if (mapx[i][j] == Floor && mapx[i - 1][j] == Wall && mapx[i - 2][j] == Floor) {
				mapx[i - 1][j] = Floor;
			}
			if (mapx[i][j] == Floor && mapx[i][j + 1] == Wall && mapx[i][j + 2] == Floor) {
				mapx[i][j + 1] = Floor;
			}
			if (mapx[i][j] == Floor && mapx[i][j - 1] == Wall && mapx[i][j - 2] == Floor) {
				mapx[i][j - 1] = Floor;
			}
			//Two Walls among two Floors
			if (mapx[i][j] == Floor && mapx[i + 1][j] == Wall && mapx[i + 2][j] == Wall && mapx[i + 3][j] == Floor) {
				mapx[i + 1][j] = Floor;
				mapx[i + 2][j] = Floor;
			}if (mapx[i][j] == Floor && mapx[i - 1][j] == Wall && mapx[i - 2][j] == Wall && mapx[i - 3][j] == Floor) {
				mapx[i - 1][j] = Floor;
				mapx[i - 2][j] = Floor;
			}if (mapx[i][j] == Floor && mapx[i][j + 1] == Wall && mapx[i][j + 2] == Wall && mapx[i][j + 3] == Floor) {
				mapx[i][j + 1] = Floor;
				mapx[i][j + 2] = Floor;
			}if (mapx[i][j] == Floor && mapx[i][j - 1] == Wall && mapx[i][j - 2] == Wall && mapx[i][j - 3] == Floor) {
				mapx[i][j + 1] = Floor;
				mapx[i][j + 2] = Floor;
			}
		}
	}

	//put the map in the text file. If there is a blank space, attempt to spawn a monster based on
	//the current dungeon level. First a roll is made to determine the level of the monster 
	//(which is between 1 and the dungeon level), then a roll is made to pick a monster from that
	//monster level's roster, then the blank space is replaced by the character representing 
	//the monster.

	// this code will also place the character and up and down stairs randomly on the map.
	bool playerSet = true;
	bool upSet = true;
	bool downSet = true;

	for (int j = 0; j < Height; j++)
	{
		for (int i = 0; i < Length; i++)
		{
			int enemyGen = rand() % 100;
			int levelx = getLevel();
			int enemylevelRoll;
			int enemyspawnRoll;
			int playerspawnRoll = rand() % (Length * Height);
			int upspawnRoll = rand() % (Length * Height);
			int downspawnRoll = rand() % (Length * Height);

			bool playerSet = true;
			bool upSet = true;
			bool downSet = true;

			if (mapx[i][j] = "." && enemyGen > 94)
			{
				enemylevelRoll = rand() % levelx;

				switch (enemylevelRoll)
				{
				case 0: // Level 1 Monsters
					enemyspawnRoll = rand() % 6;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'a';
						break;
					case 1:
						mapx[i][j] = 'g';
						break;
					case 2:
						mapx[i][j] = 'i';
						break;
					case 3:
						mapx[i][j] = 'k';
						break;
					case 4:
						mapx[i][j] = 's';
						break;
					case 5:
						mapx[i][j] = 'w';
						break;
					default:
						break;
					}
					break;
				case 1: // Level 2 Monsters
					enemyspawnRoll = rand() % 6;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'd';
						break;
					case 1:
						mapx[i][j] = 'e';
						break;
					case 2:
						mapx[i][j] = 'm';
						break;
					case 3:
						mapx[i][j] = 'q';
						break;
					case 4:
						mapx[i][j] = 't';
						break;
					case 5:
						mapx[i][j] = 'z';
						break;
					}
				case 2: // Level 3 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'h';
						break;
					case 1:
						mapx[i][j] = 'o';
						break;
					default:
						break;
					}
				case 3: //Level 4 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'j';
						break;
					case 1:
						mapx[i][j] = 'y';
						break;
					default:
						break;
					}
				case 4: //Level 5 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'c';
						break;
					case 1:
						mapx[i][j] = 'r';
						break;
					default:
						break;
					}
				case 5: //Level 6 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'f';
						break;
					case 1:
						mapx[i][j] = 'v';
						break;
					default:
						break;
					}
				case 6: // Level 7 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'j';
						break;
					case 1:
						mapx[i][j] = 'n';
						break;
					default:
						break;
					}
				case 7: // Level 8 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'p';
						break;
					case 1:
						mapx[i][j] = 'u';
						break;
					default:
						break;
					}
				case 8: // Level 9 Monsters
					enemyspawnRoll = rand() % 2;
					switch (enemyspawnRoll)
					{
					case 0:
						mapx[i][j] = 'b';
						break;
					case 1:
						mapx[i][j] = 'l';
						break;
					default:
						break;
					}

				}

			}

			if (playerSet = true)
			{

				if (mapx[i][j] = "." && playerspawnRoll <= 5)
				{
					mapx[i][j] = Player;
					playerSet = false;
				}
			}

			if (upSet = true)
			{
				if (mapx[i][j] = "." && upspawnRoll <= 5)
				{
					mapx[i][j] = UpStairs;
					upSet = false;
				}
			}

			if (downSet = true)
			{
				if (mapx[i][j] = "." && downspawnRoll <= 5)
				{
					mapx[i][j] = DownStairs;
					downSet = false;
				}


				map << mapx[i][j];
			}
			map << "\n";

		}
	}	
	map.close();
}

void Level::saveMap()
{
	if (_dungeonLevel > 1)
	{
		ifstream map("map.txt");
		ofstream SaveMap("SaveMap.txt");
		string content = "";
		int i;

		for (i = 0; map.eof() != true; i++) // get content of infile
			content += map.get();

		i--;
		content.erase(content.end() - 1);     // erase last character

		map.close();

		SaveMap << content;                 // output
		SaveMap.close();
	}
	else
	{
		ifstream map("Level1.txt");
		ofstream SaveMap("SaveMap.txt");
		string content = "";
		int i;

		for (i = 0; map.eof() != true; i++) // get content of current map
			content += map.get();

		i--;
		content.erase(content.end() - 1);     // erase last character

		map.close();

		SaveMap << content;                 // output to SaveMap.txt
		SaveMap.close();
	}
}