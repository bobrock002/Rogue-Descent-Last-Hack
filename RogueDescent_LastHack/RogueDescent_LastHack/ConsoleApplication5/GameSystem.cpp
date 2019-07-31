#include "GameSystem.h"
#include <iostream>
#include <conio.h>
#include "Enemy.h"
#include "Level.h"

//Contstructor sets up game.


GameSystem::GameSystem(string levelFileName)
{
	_level.setLevel(1); // initialize starting dungeon level at value 1.
	string name;
	char playerType;
	cout << "Choose a name: ";
	cin >> name;
	cout << "What are you in for? \nEnter B for Burglar\nEnter C for Crime Boss\nEnter E for Enforecer\nEnter H for Hitman\nEnter P for Pickpocket\nEnter S for Smuggler: ";
	cin >> playerType;
	
	_player.init(name, playerType, 1, 10, 10, 10, 10);
	_level.load(levelFileName, _player);
	_level.print();
}

void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone != true) 
	{
		_level.print();
		playerMove();
		_level.updateEnemies(_player);
	}
}

void GameSystem::playerMove() 
{
	char input;
	printf("Enter a move command (w/a/s/d): ");
	input = _getch();

	_level.movePlayer(input, _player);
}