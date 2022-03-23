#include "baseWindow.h"

baseWindow::baseWindow()
{
	m_windowSize[0] = 0;
	m_windowSize[1] = 0;

	m_windowPosition[0] = 0;
	m_windowPosition[1] = 0;

	m_backgroundColor[0] = 0.0;
	m_backgroundColor[1] = 0.0;
	m_backgroundColor[2] = 0.0;
	m_backgroundColor[3] = 1.0;
}

baseWindow::~baseWindow()
{
}

void baseWindow::SetWindowID(const std::string& id)
{
	m_id = id;
}

std::string baseWindow::GetWindowID()
{
	return m_id;
}

void baseWindow::SetWindowSize(const int& w, const int& h)
{
	m_windowSize[0] = w;
	m_windowSize[1] = h;
}

int baseWindow::GetWindowWidth()
{
	return m_windowSize[0];
}

int baseWindow::GetWindowHeight()
{
	return m_windowSize[1];
}

void baseWindow::SetWindowPosition(const int& x, const int& y)
{
	m_windowPosition[0] = x;
	m_windowPosition[1] = y;
}

int baseWindow::GetWindowPositionX()
{
	return m_windowPosition[0];
}

int baseWindow::GetWindowPositionY()
{
	return m_windowPosition[1];
}

void baseWindow::SetWindowBackgroundColor(
	const double& r, const double& g, const double& b, const double& a)
{
	m_backgroundColor[0] = r;
	m_backgroundColor[1] = g;
	m_backgroundColor[2] = b;
	m_backgroundColor[3] = a;
}

double baseWindow::SetWindowBackgroundColorRed()
{
	return m_backgroundColor[0];
}

double baseWindow::SetWindowBackgroundColorGreen()
{
	return m_backgroundColor[1];
}

double baseWindow::SetWindowBackgroundColorBlue()
{
	return m_backgroundColor[2];
}

double baseWindow::SetWindowBackgroundColorAlpha()
{
	return m_backgroundColor[3];
}
