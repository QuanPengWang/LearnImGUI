#pragma once
#pragma warning(disable:4251)
#include "gameWindowlibExport.h"
#include "baseWindow.h"

#include <vector>

class GAMEWINDOW_EXPORT menuWindow : public baseWindow
{
public:
	menuWindow();
	~menuWindow();

	void Render() override;

private:
	std::vector<std::string> m_buttons;
};
