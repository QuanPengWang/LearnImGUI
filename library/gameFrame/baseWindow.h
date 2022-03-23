#pragma once
#include "gameFramelibExport.h"
#include <string>

class GAMEFRAME_EXPORT baseWindow
{
public:
	baseWindow();
	~baseWindow();

	void SetWindowID(const std::string& id);
	std::string GetWindowID();

	void SetWindowSize(const int& w, const int& h);
	int GetWindowWidth();
	int GetWindowHeight();

	void SetWindowPosition(const int& x, const int& y);
	int GetWindowPositionX();
	int GetWindowPositionY();

	void SetWindowBackgroundColor(
		const double& r, const double& g, const double& b, const double& a);
	double SetWindowBackgroundColorRed();
	double SetWindowBackgroundColorGreen();
	double SetWindowBackgroundColorBlue();
	double SetWindowBackgroundColorAlpha();

	virtual void Render() = 0;

protected:
	std::string m_id;
	int m_windowSize[2];
	int m_windowPosition[2];
	double m_backgroundColor[4];
};
