#pragma once
#pragma warning(disable:4251)
#include "gameWindowlibExport.h"
#include "baseWindow.h"

#include <map>
#include <string>

class person;
class GAMEWINDOW_EXPORT dialogueWindow : public baseWindow
{
public:
	dialogueWindow();
	~dialogueWindow();

	void SetPerson(const std::string& n, person* p);
	person* GetPerson(const std::string& n);

	void Render() override;

private:
	person* m_player;
	std::map<std::string, person*> m_persons;
};
