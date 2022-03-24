#include "emotion.h"

emotion::emotion()
	:m_value(0), m_name(u8"平静"), m_description(u8"看起来很平静的样子")
{
}

emotion::~emotion()
{
}

void emotion::SetValue(const double& v)
{
	m_value = v;
}

double emotion::GetValue()
{
	return m_value;
}

void emotion::SetName(const std::string& name)
{
	m_name = name;
}

std::string emotion::GetName()
{
	return m_name;
}

void emotion::SetDescription(const std::string& des)
{
	m_description = des;
}

std::string emotion::GetDescription()
{
	return m_description;
}
