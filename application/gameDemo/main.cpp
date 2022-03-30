#include <iomanip>
#include <iostream>

#include "gameApplication.h"
#include "gameWindow.h"
#include "gameLoader.h"

int main(int argc, char* argv[])
{
	gameApplication app(argc, argv);

	gameWindow game;
	game.Run();

	return 0;
}