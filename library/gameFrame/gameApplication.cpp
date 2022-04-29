#include "gameApplication.h"
#include "gameLoader.h"
#include <locale>

gameApplication* gameApplication::self = 0;

gameApplication::gameApplication(int argc, char* argv[])
	:parmCount(0), m_loader(new gameLoader)
{
	//std::locale::global(std::locale(""));

	parmCount = argc;
	for (int i = 0; i < parmCount; i++)
	{
		std::string parString = std::string(argv[i]);
		parmVector.push_back(parString);
	}

	self = this;
}

gameApplication::~gameApplication()
{

}

std::string gameApplication::GetApplicationFilePath()
{
	if (parmVector.size() > 0)
		return parmVector.at(0);

	return std::string("");
}

std::string gameApplication::GetApplicationDir()
{
	if (parmVector.size() > 0)
	{
		std::string applicationFilePath = parmVector.at(0);
		std::string applicationDir;

		std::vector<std::string> resStr = split(applicationFilePath, std::string("\\"));

		size_t Count = resStr.size();
		for (int i = 0; i < Count; i++)
		{
			if (i != Count - 1)
			{
				applicationDir += resStr.at(i);
				applicationDir += std::string("\\");
			}
		}

		return applicationDir;
	}

	return std::string("");
}

std::string gameApplication::GetParam(const int& index)
{
	if (index < parmCount)
		return parmVector[index];

	return std::string();
}

bool gameApplication::LoadGame()
{
	if(!GetParam(1).empty())
	{
		m_loader->LoadGame(GetParam(1));
		return m_loader->LoadSuccess();
	}

	return false;
}

gameLoader* gameApplication::GetGameLoader() const
{
	return m_loader;
}

std::vector<std::string> gameApplication::split(std::string strtem, std::string splitStr)
{
	std::vector<std::string> strvec;

	std::string::size_type pos1, pos2;
	pos2 = strtem.find(splitStr);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		strvec.push_back(strtem.substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = strtem.find(splitStr, pos1);
	}
	strvec.push_back(strtem.substr(pos1));
	return strvec;
}
