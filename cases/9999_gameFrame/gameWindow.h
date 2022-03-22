#pragma once
#include <map>
#include <string>

//#include "person_npc.h"

class person_npc;
class gameWindow
{
public:
	gameWindow();
	~gameWindow();

	bool Run();

private:
	std::map<std::string, person_npc*> m_npcs;
};
