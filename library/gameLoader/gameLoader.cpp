#include "gameLoader.h"

#include <fstream>
#include <nlohmann/json.hpp>

class gameLoaderPrivate
{
public:
	gameLoaderPrivate(gameLoader* parent);
	~gameLoaderPrivate();

	gameLoader* m_parent = nullptr;
	nlohmann::json m_gameJson;
};

gameLoaderPrivate::gameLoaderPrivate(gameLoader* parent)
{
	m_parent = parent;
}

gameLoaderPrivate::~gameLoaderPrivate()
{
}

gameLoader::gameLoader()
	:m_private(new gameLoaderPrivate(this))
{

}

gameLoader::~gameLoader()
{

}

bool gameLoader::LoadGame(const std::string& gameFile)
{
	std::ifstream i(gameFile.c_str());
	m_private->m_gameJson.clear();
	m_private->m_gameJson << i;

	return (!m_private->m_gameJson.empty());
}

int gameLoader::GetGameVersion()
{
	if (m_private->m_gameJson.find("verson") != m_private->m_gameJson.end())
		return m_private->m_gameJson["verson"];

	return 0;
}

std::string gameLoader::GetGameName()
{
	if (m_private->m_gameJson.find("gameName") != m_private->m_gameJson.end())
		return m_private->m_gameJson["gameName"];

	return std::string();
}

std::string gameLoader::GetGameType()
{
	if (m_private->m_gameJson.find("gameType") != m_private->m_gameJson.end())
		return m_private->m_gameJson["gameType"];

	return std::string();
}
