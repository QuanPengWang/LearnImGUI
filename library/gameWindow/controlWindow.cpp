#include "controlWindow.h"
#include "person.h"
#include "person_npc.h"

#include <imgui.h>
#include <imgui_internal.h>

#include "action_greetings.h"

const float f_bWidth = 100;
const float f_bHeight = 30;

controlWindow::controlWindow()
{
}

controlWindow::~controlWindow()
{
}

void controlWindow::SetPerson(const std::string& n, person* p)
{
    if ("player" != n)
    {
        if (m_persons.find(n) == m_persons.end())
            m_persons[n] = p;
    }
    else
    {
        m_player = p;
    }
}

person* controlWindow::GetPerson(const std::string& n)
{
    if ("player" != n)
    {
        if (m_persons.find(n) != m_persons.end())
            return m_persons[n];
    }
    else
    {
        return m_player;
    }

    return nullptr;
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

    if (m_player)
    {
        std::map<uuids::uuid, action*> actions = m_player->GetInitiatives();

        int count = 0;
        for (auto a = actions.begin(); a != actions.end(); a++)
        {
            action* act = a->second;
            if (!act) continue;

            ImGuiWindow* button = nullptr;

            button = ImGui::GetCurrentWindow();
            button->DC.CursorPos.x = m_windowSize[0] - f_bWidth * (++count);

            if (ImGui::Button(act->GetName().c_str(), ImVec2(f_bWidth, f_bHeight)))
            {
                for (auto p = m_persons.begin(); p != m_persons.end(); p++)
                {
                    person* per = p->second;
                    if (!per) continue;

                    act->SetObject(per);
                    act->SetSubject(m_player);

                    per->DoAction(act);
                }
            }
        }
    }

    ImGui::PopStyleColor();
    ImGui::End();
}
