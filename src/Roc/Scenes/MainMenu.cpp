#include "Scenes/MainMenu.h"

#include <imgui.h>
#include <raylib.h>
#include <iostream>

MainMenu::MainMenu()
    :Scene("MainMenu")
{
    Image logo_temp = LoadImage("tex/TestLogo.png");
    logo  = LoadTextureFromImage(logo_temp);
    GenTextureMipmaps(&logo);
    UnloadImage(logo_temp);
}

MainMenu::~MainMenu()
{
    UnloadTexture(logo);
}

void MainMenu::RenderTitleScreen()
{
    ClearBackground(YELLOW);
    DrawTexture(logo,
        GetScreenWidth()/2 - logo.width/2,
        20,
        WHITE);
}

void MainMenu::RenderSceneSelect()
{

}

void MainMenu::SceneMain()
{

    switch (currentScreen)
    {
    case TITLE_SCREEN:
        RenderTitleScreen();
        break;
    case LEVEL_SELECT:
        RenderSceneSelect();
        break;
    default:
        break;
    }

    ImGuiWindowFlags flags = 0;
    flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground
        | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse
        | ImGuiWindowFlags_NoMove;
    ImGui::Begin("MainWindow", (bool*)__null, flags);

    ImGui::End();
}