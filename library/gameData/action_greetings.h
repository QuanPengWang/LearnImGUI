#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "action.h"

class GAMEDATA_EXPORT action_greetings : public action
{
public:
	action_greetings();
	~action_greetings();

	bool DoAction() override;

protected:
};