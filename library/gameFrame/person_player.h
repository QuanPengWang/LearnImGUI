#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include "person.h"
#include <map>

class action;
class GAMEFRAME_EXPORT person_player : public person
{
public:
	person_player();
	~person_player();

	std::string GetWord() override;

	//void DoAction(const std::string& action);
	//std::string GetAction();

	void DoAction(action* act);
	action* GetAction(baseObject* obj);

private:
	std::map<baseObject*, action*> m_actions;
};
