#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "person.h"
#include <map>

class action;
class GAMEDATA_EXPORT person_npc : public person
{
public:
	person_npc();
	~person_npc();

	std::string GetWord() override;

private:

};
