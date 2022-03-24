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
	CheckEmotion();
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

void emotion::CheckEmotion()
{
	if (m_value < 0 && -10 < m_value)
	{
		SetName(u8"不耐烦");
		SetDescription(u8"看起来略微有点烦躁");
	}
	else if (m_value <= -10 && -20 < m_value)
	{
		SetName(u8"烦躁");
		SetDescription(u8"看起来很烦躁");
	}
	else if (m_value <= -20)
	{
		SetName(u8"生气");
		SetDescription(u8"看起来生气了");
	}
}
