/***************************************************************
* 生物，生命体
****************************************************************/
#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "substance.h"
#include "organ.h"
#include "uuid.h"
#include <map>

class GAMEDATA_EXPORT organism : public substance
{
public:
	organism() {};
	~organism() {};

	virtual void DoAction(action* act);
	virtual std::vector<action*> GetActions(substance* obj);

	std::map<uuids::uuid, organ*> GetOrgans();

protected:
	std::map<uuids::uuid, organ*> m_organs;						// 组成部分，或者也可以被理解为器官
	std::map<substance*, std::vector<action*>> m_actions;		// 已经做出或者被做的动作
};

