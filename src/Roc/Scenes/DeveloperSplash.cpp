#include "Scenes/DeveloperSplash.h"
#include <raylib.h>

#include "Scenes/TitleScene.h"

void DevelSplashScene::SceneMain()
{
    totalTimeElapsed += GetFrameTime();

    BeginDrawing();

        ClearBackground(BLACK);

        int width = MeasureText("Roc Games", 100);
        int posx = (GetScreenWidth() - width) / 2;

        DrawText("Roc Games", posx, 50, 100, BLUE);

    EndDrawing();

    if (totalTimeElapsed >= 2.0f)
    {
        ChangeCurrentScene<TitleScene>();
    }
}