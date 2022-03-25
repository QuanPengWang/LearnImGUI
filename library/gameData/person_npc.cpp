#include "person_npc.h"
#include "emotion.h"
#include "action.h"

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

void person_npc::DoAction(action* act)
{
	if (!act) return;

	baseObject* sub = act->GetSubject();
	baseObject* obj = act->GetObject();

	if (this != sub && this != obj)
		return;

	if (this == obj)
	{
		// NPC被动
		act->DoAction();
		m_actions[sub] = act;
	}
	else if (this == sub)
	{
		// NPC主动
		act->DoAction();
		m_actions[obj] = act;
	}
}

action* person_npc::GetAction(baseObject* obj)
{
	if (m_actions.find(obj) != m_actions.end())
		return m_actions[obj];

	return nullptr;
}
