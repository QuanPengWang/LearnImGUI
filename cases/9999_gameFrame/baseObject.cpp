#include "baseObject.h"

baseObject::baseObject()
{
}

baseObject::~baseObject()
{
}

void baseObject::SetID(const std::string& id)
{
	m_id = id;
}

std::string baseObject::GetID()
{
	return m_id;
}
