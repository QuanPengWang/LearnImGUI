#include "controlWindow.h"
#include "personDefine.h"
#include "person.h"
#include "person_npc.h"

#include <imgui.h>
#include <imgui_internal.h>

#include "action_greetings.h"

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

    for(auto person = m_persons.begin(); person != m_persons.end(); person++)
    {
        person_npc* npc = static_cast<person_npc*>(person->second);
        if (npc)
        {
            ImGuiWindow* button = nullptr;

            button = ImGui::GetCurrentWindow();
            button->DC.CursorPos.x = m_windowSize[0] - 100;
            if (ImGui::Button(u8"打招呼", ImVec2(100, 30)))
            {
                //SetCursorPos(windowWidth - 100, 0);
                //npc->DoAction(u8"前进");
                //action_greetings* greeting = new action_greetings;
                //greeting->SetObject(npc);
                //greeting->DoAction();
                //npc->GetAction()

                action_greetings* greeting = static_cast<action_greetings*>(npc->GetAction(m_player));
                if(!greeting)
                {
                    greeting = new action_greetings;
                    greeting->SetObject(npc);
                    greeting->SetSubject(m_player);
                    
                }

                //greeting->DoAction();
                npc->DoAction(greeting);
            }
        }
    }

    

    ImGui::PopStyleColor();
    ImGui::End();
}
