#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "person.h"
#include <map>

class action;
class GAMEDATA_EXPORT person_player : public person
{
public:
	person_player();
	~person_player();

	std::string GetWord() override;

private:

};
