#ifndef _ROC_DEVEL_SPLASH_H_
#define _ROC_DEVEL_SPLASH_H_

#include "Scene.h"

class DevelSplashScene : public Scene
{
private:
    float totalTimeElapsed = 0.0f;

public:
    DevelSplashScene()
        :Scene("SplashScene") {}
    
    void SceneMain() override;
    
};

#endif