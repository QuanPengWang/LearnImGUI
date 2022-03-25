#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include "person.h"
#include <map>

class action;
class GAMEFRAME_EXPORT person_npc : public person
{
public:
	person_npc();
	~person_npc();

	std::string GetWord() override;

	void DoAction(action* act);
	action* GetAction(baseObject* obj);

private:

};
