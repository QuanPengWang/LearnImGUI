#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include <string>
#include <vector>

#define globalApp gameApplication::instance()

class gameLoader;

class GAMEFRAME_EXPORT gameApplication
{
public:
	gameApplication(int argc, char* argv[]);
	~gameApplication();

	static gameApplication* instance() { return self; };

	std::string GetApplicationFilePath();
	std::string GetApplicationDir();

	std::string GetParam(const int& index);
	bool LoadGame();

	gameLoader* GetGameLoader() const;

protected:
	std::vector<std::string> split(std::string strtem, std::string splitStr);

private:
	static gameApplication* self;
	int parmCount;
	std::vector<std::string> parmVector;
	gameLoader* m_loader;
};
