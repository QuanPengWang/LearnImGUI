#include "action.h"

action::action()
	:m_count(0), m_subject(nullptr), m_object(nullptr)
{
}

action::~action()
{
}

void action::SetSubject(baseObject* sub)
{
	m_subject = sub;
}

baseObject* action::GetSubject()
{
	return m_subject;
}

void action::SetObject(baseObject* obj)
{
	m_object = obj;
}

baseObject* action::GetObject()
{
	return m_object;
}
