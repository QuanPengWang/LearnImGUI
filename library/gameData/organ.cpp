#include "organ.h"

organ::organ()
{
}

organ::organ(const std::string& name)
{
	SetName(name);
}

organ::~organ()
{
}

bool organ::AddChildOrgan(organ* o)
{
	if (o)
	{
		std::string name = o->GetName();
		if (!name.empty() && m_childenOrgans.find(name) != m_childenOrgans.end())
		{
			m_childenOrgans[name] = o;
			return true;
		}
	}

	return false;
}

organ* organ::GetChildOrgan(const std::string& name)
{
	organ* result = nullptr;

	if (m_childenOrgans.find(name) != m_childenOrgans.end())
		result = m_childenOrgans[name];

	return result;
}

void organ::SetDescription(const std::string& des)
{
	m_des = des;
}

std::string organ::GetDescription() const
{
	return m_des;
}
