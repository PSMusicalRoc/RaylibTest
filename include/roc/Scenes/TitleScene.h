#ifndef _ROC_TITLE_SCENE_H
#define _ROC_TITLE_SCENE_H

#include "Scene.h"

class TitleScene : public Scene
{
private:


public:
    TitleScene()
        :Scene("Title") {}

    void SceneMain() override;
};

#endif