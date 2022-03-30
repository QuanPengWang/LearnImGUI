#pragma once
#include "gameLoaderlibExport.h"
#include <string>

enum loadStatus
{
	load_none = 0,
	load_noGameFile,
	load_noGameName,
	load_noGameType,
	load_noGameVersion,
	load_gameFileError,
	load_success
};

class gameLoaderPrivate;
class GAMELOADER_EXPORT gameLoader
{
public:
	gameLoader();
	~gameLoader();

	bool LoadGame(const std::string& gameFile);
	bool LoadSuccess();
	loadStatus GetLoadStatus();

	int GetGameVersion();
	std::string GetGameName();
	std::string GetGameType();

private:
	loadStatus m_loadStatus;
	gameLoaderPrivate* m_private;
};
