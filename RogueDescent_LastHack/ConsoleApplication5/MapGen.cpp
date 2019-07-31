#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include "MapGen.h"

using namespace std;

void mapGen(Level &level) {
	srand(time(NULL));

	//make map text file.
	std::fstream map;
	map.open("map.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	const int Length = 80;
	const int Height = 20;

	char Wall = '#';
	char Floor = '.';

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

	for (int j = 0; j < Height; j++) {
		for (int i = 0; i < Length; i++) {
			int enemyGen = rand() % 100;
			int levelx = level.getLevel();
			int enemylevelRoll;
			int enemyspawnRoll;
			if (mapx[i][j] = "." && enemyGen > 94)
			{
				enemylevelRoll = rand() % levelx;
				
				switch(enemylevelRoll)
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
			map << mapx[i][j];
		}
		map << "\n";
	}
}