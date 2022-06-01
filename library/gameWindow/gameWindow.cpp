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
#include <functional>
#include <GLFW/glfw3.h> 

#include "gameLoader.h"
#include "person_player.h"
#include "properties.h"

typedef std::function<void(GLFWwindow*, int, int)> windowSizeFunc;

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

    glfwSetWindowUserPointer(m_window, this);

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
    m_windows["dialogue"] = dWindow;

    controlWindow* cWindow = new controlWindow;
    cWindow->SetPerson("guide", guideNPC);
    cWindow->SetPerson("player", m_player);
    cWindow->SetWindowPosition(0, m_window_height * 0.5);
    cWindow->SetWindowSize(m_window_width * 0.5, m_window_height * 0.40625);
    m_windows["control"] = cWindow;

    gameInfoWindow* iWindow = new gameInfoWindow;
    iWindow->SetWindowPosition(m_window_width * 0.5, m_window_height * 0.5);
    iWindow->SetWindowSize(m_window_width * 0.5, m_window_height * 0.5);
    m_windows["info"] = iWindow;

    menuWindow* mWindow = new menuWindow;
    mWindow->SetWindowPosition(0, m_window_height * 0.90625);
    mWindow->SetWindowSize(m_window_width * 0.5, m_window_height * 0.09375);
    m_windows["menu"] = mWindow;

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            gameWindow* mainWindow = static_cast<gameWindow*>(glfwGetWindowUserPointer(window));
            if (!mainWindow) return;

            mainWindow->m_window_width = width;
            mainWindow->m_window_height = height;

			if(mainWindow->m_windows.find("dialogue") != mainWindow->m_windows.end())
			{
                mainWindow->m_windows["dialogue"]->SetWindowPosition(0, 0);
                mainWindow->m_windows["dialogue"]->SetWindowSize(mainWindow->m_window_width, mainWindow->m_window_height * 0.5);
			}

            if (mainWindow->m_windows.find("control") != mainWindow->m_windows.end())
            {
                mainWindow->m_windows["control"]->SetWindowPosition(0, mainWindow->m_window_height * 0.5);
                mainWindow->m_windows["control"]->SetWindowSize(mainWindow->m_window_width * 0.5, mainWindow->m_window_height * 0.40625);
            }

            if (mainWindow->m_windows.find("info") != mainWindow->m_windows.end())
            {
                mainWindow->m_windows["info"]->SetWindowPosition(mainWindow->m_window_width * 0.5, mainWindow->m_window_height * 0.5);
                mainWindow->m_windows["info"]->SetWindowSize(mainWindow->m_window_width * 0.5, mainWindow->m_window_height * 0.5);
            }

            if (mainWindow->m_windows.find("menu") != mainWindow->m_windows.end())
            {
                mainWindow->m_windows["menu"]->SetWindowPosition(0, mainWindow->m_window_height * 0.90625);
                mainWindow->m_windows["menu"]->SetWindowSize(mainWindow->m_window_width * 0.5, mainWindow->m_window_height * 0.09375);
            }

        });
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

        for(auto it = m_windows.begin(); it != m_windows.end(); it++)
        {
	        if(!it->second) continue;
            it->second->Render();
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
