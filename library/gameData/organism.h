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

	/// <summary>
	/// 已经做出或者被做的动作
	/// substance 为本身的时候，代表这个动作无受用者
	/// substance 为 allSubstance，代表这个动作对于所有的物体
	/// </summary>
	std::map<substance*, std::vector<action*>> m_actions;
};

