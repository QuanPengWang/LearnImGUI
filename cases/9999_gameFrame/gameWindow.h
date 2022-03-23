#pragma once
#include <map>
#include <vector>
#include <string>

class person;
class baseWindow;
struct GLFWwindow;
struct ImVec4;
class gameWindow
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
