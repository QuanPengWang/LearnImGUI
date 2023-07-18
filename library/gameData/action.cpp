#include "action.h"

action::action()
	:m_count(0), m_subject(nullptr), m_object(nullptr)
{
}

action::~action()
{
}

void action::SetSubject(substance* sub)
{
	m_subject = sub;
}

substance* action::GetSubject()
{
	return m_subject;
}

void action::SetObject(substance* obj)
{
	m_object = obj;
}

substance* action::GetObject()
{
	return m_object;
}
