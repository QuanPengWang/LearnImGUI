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

	virtual void DoAction(action* act);
	virtual std::vector<action*> GetActions(baseObject* obj);

	std::map<uuids::uuid, organ*> GetOrgans();

protected:
	std::map<uuids::uuid, organ*> m_organs;						// 组成部分，或者也可以被理解为器官
	std::map<baseObject*, std::vector<action*>> m_actions;		// 已经做出或者被做的动作
};

