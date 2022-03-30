#pragma once
#pragma warning(disable:4251)
#include "gameWindowlibExport.h"
#include "baseWindow.h"

class gameLoader;
class GAMEWINDOW_EXPORT gameInfoWindow : public baseWindow
{
public:
	gameInfoWindow();
	~gameInfoWindow();

	void Render() override;

private:
	gameLoader* m_loader;
};
