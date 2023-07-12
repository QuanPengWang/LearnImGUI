#include "organism.h"

std::map<uuids::uuid, organ*> organism::GetOrgans()
{
	return m_organs;
}
