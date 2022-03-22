#include "person_npc.h"

person_npc::person_npc()
{
}

person_npc::~person_npc()
{
}

std::string person_npc::GetWord()
{
	return u8"你好 !";
}

void person_npc::DoAction(const std::string& action)
{
	m_actionTest = action;
}

std::string person_npc::GetAction()
{
	return m_actionTest;
}
