#pragma once
#include "gameFramelibExport.h"
#include <string>
#include <vector>

#define globalApp gameApplication::instance()

class GAMEFRAME_EXPORT gameApplication
{
public:
	gameApplication(int argc, char* argv[]);
	~gameApplication();

	static gameApplication* instance() { return self; };

	std::string GetApplicationFilePath();
	std::string GetApplicationDir();

protected:
	std::vector<std::string> split(std::string strtem, std::string splitStr);

private:
	static gameApplication* self;
	int parmCount = 0;
	std::vector<std::string> parmVector;
};
