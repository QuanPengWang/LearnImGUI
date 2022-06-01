#include "gameWindow.h"
#include "gameApplication.h"
#include "controlWindow.h"
#include "dialogueWindow.h"
#include "gameInfoWindow.h"
#include "menuWindow.h"
#include "person_npc.h"

// imgui
#include <imgui.h>
#include <imconfig.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>

// 
#include <iostream>

// Will drag system OpenGL headers
#include <GLFW/glfw3.h> 

#include "gameLoader.h"
#include "person_player.h"
#include "properties.h"

gameWindow::gameWindow()
	:m_glfw_initFlag(false), m_window(nullptr)
{
    if (!glfwInit()) return;

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    m_window = glfwCreateWindow(1280, 720,
        u8"简单的游戏框架", nullptr, nullptr);

    // full screen
    //GLFWwindow* window = glfwCreateWindow(1280, 720,
    //    u8"简单的游戏框架", glfwGetPrimaryMonitor(), nullptr);

    if (!m_window) return;

    m_glfw_initFlag = true;
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1); // Enable vsync

    // 窗口最大化
    glfwMaximizeWindow(m_window);
    glfwGetWindowSize(m_window, &m_window_width, &m_window_height);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // GetGlyphRangesChineseSimplifiedCommon 加载的中文字符集不全
    io.Fonts->AddFontFromFileTTF("c:/windows/fonts/simhei.TTF", 18.0f,
        nullptr, io.Fonts->GetGlyphRangesChineseFull());

    //ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    m_clear_color = new ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    gameLoader* loader = globalApp->GetGameLoader();
    if(loader && loader->LoadSuccess())
    {
	    
    }

    person_npc* guideNPC = new person_npc;
    guideNPC->SetName(u8"游戏初始向导");
    m_npcs["guide"] = guideNPC;

    properties* book = new properties;
    book->SetName(u8"书");
    m_npcs["guide"]->SetProperties(book);

    m_player = new person_player;
    m_player->SetName(u8"玩家");

    dialogueWindow* dWindow = new dialogueWindow;
    dWindow->SetPerson("guide", guideNPC);
    dWindow->SetPerson("player", m_player);
    dWindow->SetWindowPosition(0, 0);
    dWindow->SetWindowSize(m_window_width, m_window_height * 0.5);
    m_windows.push_back(dWindow);

    controlWindow* cWindow = new controlWindow;
    cWindow->SetPerson("guide", guideNPC);
    cWindow->SetPerson("player", m_player);
    cWindow->SetWindowPosition(0, m_window_height * 0.5);
    cWindow->SetWindowSize(m_window_width * 0.5, m_window_height * 0.40625);
    m_windows.push_back(cWindow);

    gameInfoWindow* iWindow = new gameInfoWindow;
    iWindow->SetWindowPosition(m_window_width * 0.5, m_window_height * 0.5);
    iWindow->SetWindowSize(m_window_width * 0.5, m_window_height * 0.5);
    m_windows.push_back(iWindow);

    menuWindow* mWindow = new menuWindow;
    mWindow->SetWindowPosition(0, m_window_height * 0.90625);
    mWindow->SetWindowSize(m_window_width * 0.5, m_window_height * 0.09375);
    m_windows.push_back(mWindow);
}
	
gameWindow::~gameWindow()
{
}

bool gameWindow::Run()
{
    // Main loop
    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        for(int i = 0; i < m_windows.size(); i++)
        {
	        if(!m_windows[i]) continue;
            m_windows[i]->Render();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(m_clear_color->x * m_clear_color->w, 
            m_clear_color->y * m_clear_color->w, m_clear_color->z * m_clear_color->w, 
            m_clear_color->w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_window);
    glfwTerminate();

    return true;
}
