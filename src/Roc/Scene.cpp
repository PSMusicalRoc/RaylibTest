#include "Scene.h"

Scene* currentScene = nullptr;

void UnloadCurrentScene()
{
    if (currentScene != nullptr)
    {
        delete currentScene;
    }
}