#include "gameWindow.h"

#include "mainWindow.h"
#include <cstdio>

#include <imgui.h>
#include <imconfig.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <iostream>

#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#include "person_npc.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

gameWindow::gameWindow()
{
    person_npc* guideNPC = new person_npc;
    guideNPC->SetName(u8"游戏初始向导");
    m_npcs["guide"] = guideNPC;
}

gameWindow::~gameWindow()
{
}

bool gameWindow::Run()
{
	if (!glfwInit())
		return false;

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720,
        u8"简单的游戏框架", nullptr, nullptr);

    // full screen
    //GLFWwindow* window = glfwCreateWindow(1280, 720,
    //    u8"简单的游戏框架", glfwGetPrimaryMonitor(), nullptr);

    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // 窗口最大化
    glfwMaximizeWindow(window);

    int windowWidth = 0;
    int windowHeight = 0;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // GetGlyphRangesChineseSimplifiedCommon 加载的中文字符集不全
    io.Fonts->AddFontFromFileTTF("c:/windows/fonts/simhei.TTF", 18.0f,
        nullptr, io.Fonts->GetGlyphRangesChineseFull());

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight - 400), ImGuiCond_Always);

            ImGui::Begin(u8"显示窗口", nullptr, 
                ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
            //ImGui::Text(u8"游戏主窗口");
            ImGui::Text(m_npcs["guide"]->GetWord().c_str());
            ImGui::Text(u8"我是");
            ImGui::SameLine();
            ImGui::Text(m_npcs["guide"]->GetName().c_str());

            std::string npcAction = m_npcs["guide"]->GetAction();
            if(!npcAction.empty())
            {
                ImGui::Text(u8"你是让我");
                ImGui::SameLine();
                ImGui::Text(npcAction.c_str());
                ImGui::SameLine();
                ImGui::Text(u8"吗？");
            }

            person_emotion emotion = m_npcs["guide"]->GetEmotion();
            if(0 != emotion.id)
            {
                ImGui::Text(m_npcs["guide"]->GetName().c_str());
                ImGui::SameLine();
                ImGui::Text(emotion.m_description.c_str());
            }

            ImGui::End();
        }

        {
            ImGui::SetNextWindowPos(ImVec2(0, windowHeight - 400));
            ImGui::SetNextWindowSize(ImVec2(windowWidth, 400), ImGuiCond_Always);

            ImGui::Begin(u8"操控窗口", nullptr, 
                ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
            //ImGui::Text(u8"游戏操控窗口");

            if(ImGui::Button(u8"前进"))
            {
                m_npcs["guide"]->DoAction(u8"前进");
            }

            if (ImGui::Button(u8"后退"))
            {
                m_npcs["guide"]->DoAction(u8"后退");
            }

            if (ImGui::Button(u8"左转"))
            {
                m_npcs["guide"]->DoAction(u8"左转");
            }

            if (ImGui::Button(u8"右转"))
            {
                m_npcs["guide"]->DoAction(u8"右转");
            }

            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return true;
}
