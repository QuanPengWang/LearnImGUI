#pragma once
#include "gameLoaderlibExport.h"
#include <string>

class gameLoaderPrivate;
class GAMELOADER_EXPORT gameLoader
{
public:
	gameLoader();
	~gameLoader();

	bool LoadGame(const std::string& gameFile);

	int GetGameVersion();
	std::string GetGameName();
	std::string GetGameType();

private:
	gameLoaderPrivate* m_private;
};
