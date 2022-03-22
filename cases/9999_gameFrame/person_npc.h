#pragma once
#include "person.h"

class person_npc : public person
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
