#include <iomanip>
#include <iostream>

#include "gameApplication.h"
#include "gameWindow.h"
#include "gameLoader.h"

int main(int argc, char* argv[])
{
	gameApplication app(argc, argv);

	if(2 <= argc)
	{
		gameLoader loader;
		loader.LoadGame(std::string(argv[1]));

		std::setw(20);
		std::cout << "Load Game : " << loader.GetGameName() << std::endl;
		std::cout << "Game Type : " << loader.GetGameType() << std::endl;
		std::cout << "Game Version : " << loader.GetGameVersion() << std::endl;
	}
		

	gameWindow game;
	game.Run();

	return 0;
}