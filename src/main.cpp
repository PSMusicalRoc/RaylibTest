#include <iostream>
#include <raylib.h>

#include "AllScenes.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "RaylibTest!");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    ChangeCurrentScene<DevelSplashScene>();


    while (!WindowShouldClose())
    {
        currentScene->SceneMain();
    }

    UnloadCurrentScene();
    CloseWindow();
    return 0;
}