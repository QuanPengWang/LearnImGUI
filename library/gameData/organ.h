/***************************************************************
* 器官，生物的物理组成部分
****************************************************************/
#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "baseObject.h"

#include <map>

class GAMEDATA_EXPORT organ : public baseObject
{
public:
	organ();
	organ(const std::string& name);
	~organ();

	bool AddChildOrgan(organ* o);
	organ* GetChildOrgan(const uuids::uuid& uid);

	void SetDescription(const std::string& des);
	std::string GetDescription() const;

protected:
	std::string m_des;
	std::map<uuids::uuid, organ*> m_childenOrgans;
};