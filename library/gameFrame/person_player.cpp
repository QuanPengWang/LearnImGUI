#include "person_player.h"

#include "action.h"
#include "emotion.h"

person_player::person_player()
{
}

person_player::~person_player()
{
}

std::string person_player::GetWord()
{
	return u8"你好 !";
}

void person_player::DoAction(action* act)
{
	//m_actionTest = action;
	//m_doActionCount++;

	//if (10 < m_doActionCount)
	//{
	//	m_emotion->SetValue(-1);
	//	m_emotion->SetName(u8"烦躁");
	//	m_emotion->SetDescription(u8"看上去略微有一些烦躁。");
	//}

	if (!act) return;

	baseObject* sub = act->GetSubject();
	baseObject* obj = act->GetObject();

	if (this != sub && this != obj)
		return;

	if(this == obj)
	{
		// 玩家被动

	}
	else if(this == sub)
	{
		// 玩家主动

	}
}

action* person_player::GetAction(baseObject* obj)
{
	if (m_actions.find(obj) != m_actions.end())
		return m_actions[obj];

	return nullptr;
}
