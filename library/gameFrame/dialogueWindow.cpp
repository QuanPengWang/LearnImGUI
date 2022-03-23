#include "dialogueWindow.h"
#include "personDefine.h"
#include "person.h"
#include "person_npc.h"

#include <imgui.h>



dialogueWindow::dialogueWindow()
	:m_person(nullptr)
{
}

dialogueWindow::~dialogueWindow()
{
}

void dialogueWindow::SetPerson(person* p)
{
    m_person = p;
}

person* dialogueWindow::GetPerson()
{
    return m_person;
}

void dialogueWindow::Render()
{
    ImGui::SetNextWindowPos(ImVec2(m_windowPosition[0], m_windowPosition[1]));
    ImGui::SetNextWindowSize(ImVec2(m_windowSize[0], m_windowSize[1]), ImGuiCond_Always);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, 
        ImVec4(m_backgroundColor[0], m_backgroundColor[1], m_backgroundColor[2], m_backgroundColor[3]));

    ImGui::Begin(u8"显示窗口", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    person_npc* npc = static_cast<person_npc*>(m_person);
    if(npc)
    {
        ImGui::Text(npc->GetWord().c_str());
        ImGui::Text(u8"我是");
        ImGui::SameLine();
        ImGui::Text(npc->GetName().c_str());

        std::string npcAction = npc->GetAction();
        if (!npcAction.empty())
        {
            ImGui::Text(u8"你是让我");
            ImGui::SameLine();
            ImGui::Text(npcAction.c_str());
            ImGui::SameLine();
            ImGui::Text(u8"吗？");
        }

        person_emotion emotion = npc->GetEmotion();
        if (0 != emotion.id)
        {
            ImGui::Text(npc->GetName().c_str());
            ImGui::SameLine();
            ImGui::Text(emotion.m_description.c_str());
        }
    }

    ImGui::PopStyleColor();
    ImGui::End();
}
