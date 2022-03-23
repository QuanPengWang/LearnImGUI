#pragma once
#include "gameFramelibExport.h"
#include "person.h"

class GAMEFRAME_EXPORT person_npc : public person
{
public:
	person_npc();
	~person_npc();

	std::string GetWord() override;

	void DoAction(const std::string& action);
	std::string GetAction();

private:
	int m_doActionCount;
	std::string m_actionTest;
};
