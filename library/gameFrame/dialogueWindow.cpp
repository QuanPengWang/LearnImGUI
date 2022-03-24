#include "dialogueWindow.h"
#include "personDefine.h"
#include "person.h"
#include "person_npc.h"
#include "emotion.h"
#include <imgui.h>

dialogueWindow::dialogueWindow()
{
}

dialogueWindow::~dialogueWindow()
{
}

void dialogueWindow::SetPerson(const std::string& n, person* p)
{
    if("player" != n)
    {
        if (m_persons.find(n) == m_persons.end())
            m_persons[n] = p;
    }
    else
    {
        m_player = p;
    }
}

person* dialogueWindow::GetPerson(const std::string& n)
{
    if("player" != n)
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

void dialogueWindow::Render()
{
    ImGui::SetNextWindowPos(ImVec2(m_windowPosition[0], m_windowPosition[1]));
    ImGui::SetNextWindowSize(ImVec2(m_windowSize[0], m_windowSize[1]), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, 
        ImVec4(m_backgroundColor[0], m_backgroundColor[1], m_backgroundColor[2], m_backgroundColor[3]));

    ImGui::Begin(u8"显示窗口", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    for(auto person = m_persons.begin(); person != m_persons.end(); person++)
    {
        person_npc* npc = static_cast<person_npc*>(person->second);
        if (npc)
        {
            ImGui::Text(npc->GetWord().c_str());
            ImGui::Text(u8"我是");
            ImGui::SameLine();
            ImGui::Text(npc->GetName().c_str());

            emotion* emotion = npc->GetEmotion();
            if (emotion)
            {
                ImGui::Text(npc->GetName().c_str());
                ImGui::SameLine();
                ImGui::Text(emotion->GetDescription().c_str());
            }
        }
    }

    

    ImGui::PopStyleColor();
    ImGui::End();
}
