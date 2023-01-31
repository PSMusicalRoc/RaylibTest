#ifndef _ROC_CONSOLE_SCENE_H_
#define _ROC_CONSOLE_SCENE_H_

#include "Scene.h"
#include <sstream>
#include <raylib.h>
#include <imgui.h>

#include <map>
#include <functional>

typedef std::function<std::string(std::string&)> ConsoleCommand;

class ConsoleScene : public Scene
{
private:
    static std::stringstream stream;
    std::string curr_text;
    bool scroll_to_bottom = false;

    std::map<std::string, ConsoleCommand> _commands;

    static Sound* sounds;
    static unsigned int NUMSOUNDS;

private:
    static int TextCallback(ImGuiInputTextCallbackData* data);
    bool LoadSceneAssets();
    std::string callCallback(std::string& command);

private:
    static std::string print(std::string& args);
    static std::string ssl(std::string& args);
    static std::string clear(std::string& args);

public:
    ConsoleScene()
        :Scene("Console")
    {
        LoadSceneAssets();
    }
    void SceneMain() override;
    ~ConsoleScene()
    {
        for (int i = 0; i < NUMSOUNDS; i++)
        {
            UnloadSound(*(sounds + i));
        }
        delete [] sounds;
    }
};

#endif
