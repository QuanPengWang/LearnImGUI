/***************************************************************
* 生物，生命体
****************************************************************/
#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "baseObject.h"
#include "organ.h"
#include <map>

class GAMEDATA_EXPORT organism : public baseObject
{
public:
	organism() {};
	~organism() {};

	std::map<std::string, organ*> GetOrgans();

protected:
	std::map<std::string, organ*> m_organs;
};

