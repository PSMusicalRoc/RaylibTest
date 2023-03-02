#ifndef _ROC_MAIN_MENU_H_
#define _ROC_MAIN_MENU_H_

#include "Scene.h"
#include <raylib.h>

class MainMenu : public Scene
{
private:
    void RenderTitleScreen();
    void RenderSceneSelect();

    Texture2D logo;

    int currentScreen = 0;

    enum {
        TITLE_SCREEN = 0,
        LEVEL_SELECT
    };

public:
    MainMenu();
    ~MainMenu();
    void SceneMain() override;
};

#endif