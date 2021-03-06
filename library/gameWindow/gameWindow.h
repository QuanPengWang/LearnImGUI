#pragma once
#pragma warning(disable:4251)
#include "gameWindowlibExport.h"
#include <map>
#include <vector>
#include <string>

class person;
class baseWindow;
struct GLFWwindow;
struct ImVec4;
class GAMEWINDOW_EXPORT gameWindow
{
public:
	gameWindow();
	~gameWindow();

	bool Run();

private:
	bool m_glfw_initFlag;
	GLFWwindow* m_window;

	int m_window_width;
	int m_window_height;

	person* m_player;
	std::map<std::string, person*> m_npcs;
	std::map<std::string, baseWindow*> m_windows;

	ImVec4* m_clear_color;
};
