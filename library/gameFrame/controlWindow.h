#pragma once
#include "gameFramelibExport.h"
#include "baseWindow.h"

class person;
class GAMEFRAME_EXPORT controlWindow : public baseWindow
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
