#pragma once
#include "baseWindow.h"

class person;
class dialogueWindow : public baseWindow
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
