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
		uuids::uuid uid = o->GetID();
		if (!uid.is_nil() && m_childenOrgans.find(uid) != m_childenOrgans.end())
		{
			m_childenOrgans[uid] = o;
			return true;
		}
	}

	return false;
}

organ* organ::GetChildOrgan(const uuids::uuid& uid)
{
	organ* result = nullptr;

	if (m_childenOrgans.find(uid) != m_childenOrgans.end())
		result = m_childenOrgans[uid];

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
