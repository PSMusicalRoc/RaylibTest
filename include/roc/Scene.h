#ifndef _ROC_SCENE_H_
#define _ROC_SCENE_H_

#include <string>

class Scene
{
private:
    std::string name;

public:
    Scene(const std::string name)
        :name(name) {}
    
    virtual void SceneMain() = 0;

};

extern Scene* currentScene;

template <typename T>
void ChangeCurrentScene()
{
    if (currentScene != nullptr)
    {
        delete currentScene;
    }
    currentScene = new T();
}

void UnloadCurrentScene();

#endif