/***************************************************************
* 生物，生命体
****************************************************************/
#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "baseObject.h"
#include "organ.h"
#include "uuid.h"
#include <map>

class GAMEDATA_EXPORT organism : public baseObject
{
public:
	organism() {};
	~organism() {};

	std::map<uuids::uuid, organ*> GetOrgans();

protected:
	std::map<uuids::uuid, organ*> m_organs;
};

