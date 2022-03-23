#pragma once
#include "gameFramelibExport.h"
#include "baseWindow.h"

class person;
class GAMEFRAME_EXPORT dialogueWindow : public baseWindow
{
public:
	dialogueWindow();
	~dialogueWindow();

	void SetPerson(person* p);
	person* GetPerson();

	void Render() override;

private:
	person* m_person;
};
