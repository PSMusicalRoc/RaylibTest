#include <iostream>
#include <raylib.h>
#include <rlgl.h>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include "AllScenes.h"

#include "Scenes/TestText.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 800;
    

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    InitWindow(screenWidth, screenHeight, "RaylibTest!");
    InitAudioDevice();


    IMGUI_CHECKVERSION();
    ImGuiContext* con = ImGui::CreateContext();
    ImGui::SetCurrentContext(con);
    ImGuiIO& io = ImGui::GetIO();

    ImFont* ocra = io.Fonts->AddFontFromFileTTF("font/OCRAEXT.TTF", 30);

    GLFWwindow *glfwWindow = glfwGetCurrentContext();
    ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    ChangeCurrentScene<ConsoleScene>();


    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        currentScene->SceneMain();

        rlDrawRenderBatchActive();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        EndDrawing();
    }

    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext(con);

    CloseAudioDevice();
    UnloadCurrentScene();
    CloseWindow();
    return 0;
}