#include "organism.h"
#include "action.h"

void organism::DoAction(action* act)
{
	if (!act) return;

	substance* sub = act->GetSubject();
	if (!sub)
		sub = this;

	act->DoAction();

	std::vector<action*> acts;
	if (m_actions.find(sub) != m_actions.end())
		acts = m_actions[sub];

	acts.push_back(act);
	m_actions[sub] = acts;
}

std::vector<action*> organism::GetActions(substance* obj)
{
	if (m_actions.find(obj) != m_actions.end())
		return m_actions[obj];

	return std::vector<action*>();
}

std::map<uuids::uuid, organ*> organism::GetOrgans()
{
	return m_organs;
}
