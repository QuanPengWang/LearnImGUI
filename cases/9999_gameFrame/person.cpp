#include "person.h"

person::person()
{
}

person::~person()
{
}

void person::SetName(const std::string& name)
{
	m_name = name;
}

std::string person::GetName()
{
	return m_name;
}
