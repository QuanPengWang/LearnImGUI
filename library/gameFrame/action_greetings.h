#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include "action.h"

class GAMEFRAME_EXPORT action_greetings : public action
{
public:
	action_greetings();
	~action_greetings();

	bool DoAction() override;

protected:
};