// This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "GameSystem.h"

using namespace std;


int main()
{

	GameSystem GameSystem("Level1.txt");

	GameSystem.playGame();

	return 0;
}
