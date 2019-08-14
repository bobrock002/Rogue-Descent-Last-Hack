#include "pch.h"
#include "GameSystem.h"
#include <iostream>
#include <conio.h>
#include "Enemy.h"
#include "Level.h"
#include <fstream>
#include <stdlib.h>
#include <sstream>
//Contstructor sets up game.


GameSystem::GameSystem(string levelFileName)
{
	_level.setLevel(1); // initialize starting dungeon level at value 1.
	string name;
	char playerType;
	int gameChoice;
	_level.mapGen();
	cout << "(1) New game\n(2) Load saved game\n";
	cout << "Enter your choice: ";
	cin >> gameChoice;

	switch (gameChoice)
	{
	case 1: // New Game
		cout << "Choose a name: ";
		cin >> name;
		cout << "What are you in for? \nEnter B for Burglar\nEnter C for Crime Boss\nEnter E for Enforecer\nEnter H for Hitman\nEnter P for Pickpocket\nEnter S for Smuggler: ";
		cin >> playerType;

		_player.init(name, playerType, 1, 10, 10, 20, 10);
		_level.load(levelFileName, _player);
		_level.print();
		_player.printPlayer(_player);
		break;

	case 2: // Load Saved Game
		_player.init("Blank", 'B', 1, 10, 10, 10, 10);
		_player.loadPlayer(_player);
		_level.load("saveMap.txt", _player);
		_level.print();
		_player.printPlayer(_player);
		break;
	default:
		break;
	}
}

void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone != true)
	{
		_level.print();
		_player.printPlayer(_player);
		playerMove();
		if (_player.get_currentHealth() < _player.get_maxHealth())
		{
			_player.add_currentHealth(1);
		}
		_level.updateEnemies(_player);
	}
}

void GameSystem::playerMove()
{
	char input;


	printf("Enter a move command (w/a/s/d) or enter (g) to save the game: ");
	input = _getch();

	_level.movePlayer(input, _player);

}