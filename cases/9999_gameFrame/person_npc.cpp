#include "person_npc.h"

person_npc::person_npc()
	:m_doActionCount(0)
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
	m_doActionCount++;

	if(10 < m_doActionCount)
	{
		m_emotion.id = -1;
		m_emotion.m_name = u8"略微有点烦躁。";
		m_emotion.m_description = u8"看上去略微有一些烦躁。";
	}
}

std::string person_npc::GetAction()
{
	return m_actionTest;
}
