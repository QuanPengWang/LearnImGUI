#include "menuWindow.h"
#include <imgui.h>

menuWindow::menuWindow()
{
    m_buttons.push_back(u8"人物");
    m_buttons.push_back(u8"任务");
    m_buttons.push_back(u8"背包");
    m_buttons.push_back(u8"系统");
}

menuWindow::~menuWindow()
{

}

void menuWindow::Render()
{
    ImGui::SetNextWindowPos(ImVec2(m_windowPosition[0], m_windowPosition[1]));
    ImGui::SetNextWindowSize(ImVec2(m_windowSize[0], m_windowSize[1]), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg,
        ImVec4(m_backgroundColor[0], m_backgroundColor[1], m_backgroundColor[2], m_backgroundColor[3]));

    ImGui::Begin(u8"游戏菜单", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    //int button
    ImVec2 buttonSize(m_windowSize[0] / m_buttons.size() - 100, 
        m_windowSize[1] - 20);

    for(int i = 0; i < m_buttons.size(); i++)
    {
        if (0 < i)
            ImGui::SameLine();

        if (ImGui::Button(m_buttons[i].c_str(), buttonSize))
        {

        }
    }

    ImGui::PopStyleColor();
    ImGui::End();
}
