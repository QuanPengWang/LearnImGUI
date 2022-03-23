#include "controlWindow.h"
#include "personDefine.h"
#include "person.h"
#include "person_npc.h"

#include <imgui.h>
#include <imgui_internal.h>

controlWindow::controlWindow()
    :m_person(nullptr)
{
}

controlWindow::~controlWindow()
{
}

void controlWindow::SetPerson(person* p)
{
    m_person = p;
}

person* controlWindow::GetPerson()
{
    return m_person;
}

void controlWindow::Render()
{
    ImGui::SetNextWindowPos(ImVec2(m_windowPosition[0], m_windowPosition[1]));
    ImGui::SetNextWindowSize(ImVec2(m_windowSize[0], m_windowSize[1]), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg,
        ImVec4(m_backgroundColor[0], m_backgroundColor[1], m_backgroundColor[2], m_backgroundColor[3]));


    ImGui::Begin(u8"操控窗口", nullptr, 
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    //ImGui::Text(u8"游戏操控窗口");

    person_npc* npc = static_cast<person_npc*>(m_person);
    if (npc)
    {
        ImGuiWindow* button = nullptr;

        button = ImGui::GetCurrentWindow();
        button->DC.CursorPos.x = m_windowSize[0] - 100;
        if (ImGui::Button(u8"前进", ImVec2(100, 30)))
        {
            //SetCursorPos(windowWidth - 100, 0);
            npc->DoAction(u8"前进");
        }

        button = ImGui::GetCurrentWindow();
        button->DC.CursorPos.x = m_windowSize[0] - 100;
        if (ImGui::Button(u8"后退", ImVec2(100, 30)))
        {
            npc->DoAction(u8"后退");
        }

        button = ImGui::GetCurrentWindow();
        button->DC.CursorPos.x = m_windowSize[0] - 100;
        if (ImGui::Button(u8"左转", ImVec2(100, 30)))
        {
            npc->DoAction(u8"左转");
        }

        button = ImGui::GetCurrentWindow();
        button->DC.CursorPos.x = m_windowSize[0] - 100;
        if (ImGui::Button(u8"右转", ImVec2(100, 30)))
        {
            npc->DoAction(u8"右转");
        }
    }

    ImGui::PopStyleColor();
    ImGui::End();
}
