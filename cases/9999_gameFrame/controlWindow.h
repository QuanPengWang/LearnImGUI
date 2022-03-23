#pragma once
#include "baseWindow.h"

class person;
class controlWindow : public baseWindow
{
public:
	controlWindow();
	~controlWindow();

	void SetPerson(person* p);
	person* GetPerson();

	void Render() override;

private:
	person* m_person;
};
