#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include <map>
#include <vector>
#include <string>

class person;
class baseWindow;
struct GLFWwindow;
struct ImVec4;
class GAMEFRAME_EXPORT gameWindow
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

	std::map<std::string, person*> m_npcs;
	std::vector<baseWindow*> m_windows;

	ImVec4* m_clear_color;
};
