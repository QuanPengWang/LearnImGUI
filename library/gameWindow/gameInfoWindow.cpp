#include "gameInfoWindow.h"
#include "gameApplication.h"
#include "gameLoader.h"

#include <map>
#include <string>
#include <sstream>
#include <imgui.h>

gameInfoWindow::gameInfoWindow()
{
	m_loader = new gameLoader;
	m_loader->LoadGame(globalApp->GetParam(1));
}

gameInfoWindow::~gameInfoWindow()
{
}

void gameInfoWindow::Render()
{
    ImGui::SetNextWindowPos(ImVec2(m_windowPosition[0], m_windowPosition[1]));
    ImGui::SetNextWindowSize(ImVec2(m_windowSize[0], m_windowSize[1]), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg,
        ImVec4(m_backgroundColor[0], m_backgroundColor[1], m_backgroundColor[2], m_backgroundColor[3]));

    ImGui::Begin(u8"游戏信息", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    if (m_loader->LoadSuccess())
    {
        ImGui::Text(m_loader->GetGameName().c_str());
        ImGui::Text(m_loader->GetGameType().c_str());

        std::string s;
        std::stringstream ss(s);
        ss << m_loader->GetGameVersion();
        ImGui::Text(ss.str().c_str());
    }
    else
    {
        ImGui::Text(u8"游戏加载失败！");
    }

    ImGui::PopStyleColor();
    ImGui::End();
}
