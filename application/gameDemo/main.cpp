#include "gameApplication.h"
#include "gameWindow.h"

int main(int argc, char* argv[])
{
	gameApplication app(argc, argv);

	gameWindow game;
	game.Run();

	return 0;
}