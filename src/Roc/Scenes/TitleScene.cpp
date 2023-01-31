#include "Scenes/TitleScene.h"
#include <raylib.h>

void TitleScene::SceneMain()
{
    ClearBackground(WHITE);

    int width = MeasureText("Title Screen", 40);
    int posx = (GetScreenWidth() - width) / 2;

    DrawText("Title Screen", posx, 50, 40, BLACK);
}