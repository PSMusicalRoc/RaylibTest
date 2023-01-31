#include "Scenes/ConsoleScene.h"

#include <raylib.h>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <iostream>

#include "Utils/ColoredText.h"

/*
|=========|
| STATICS |
|=========|
*/

std::stringstream ConsoleScene::stream;

unsigned int ConsoleScene::NUMSOUNDS = 0;
Sound* ConsoleScene::sounds = nullptr;

/*
|==================|
| CONSOLE COMMANDS |
|==================|
*/

void colorEncode(std::string& str)
{
    ImVec4 def_text_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);
    std::string out_str = "";
    out_str += UTILITYCHAR + std::string("[0, .5, 1, 1]User>");
    out_str += UTILITYCHAR + std::string("[");
    
    out_str += std::to_string(def_text_col.x) + "," + std::to_string(def_text_col.y) +
        "," + std::to_string(def_text_col.z) + "," + std::to_string(def_text_col.w) + "]";
    str = out_str + str;
}

std::string ConsoleScene::callCallback(std::string& command)
{
    size_t first_space = command.find(" ");
    std::string _cmd = "";
    std::string args = "";
    if (first_space == command.npos)
    {
        // Whole string is command
        _cmd = command;
        args = "";
    } else {
        _cmd = command.substr(0, first_space);
        args = command.substr(first_space + 1);
    }

    if (_commands.find(_cmd) != _commands.end())
    {
        // call command, return output
        return (_commands.at(_cmd))(args);
    } else {
        return "Could not find program: " + _cmd;
    }
}

std::string ConsoleScene::print(std::string& args)
{
    return args;
}

std::string ConsoleScene::ssl(std::string& args)
{
    return "ssl acquired";
}

std::string ConsoleScene::clear(std::string& args)
{
    stream.str("");
    return "";
}

bool ConsoleScene::LoadSceneAssets()
{
    NUMSOUNDS = 3;
    if (sounds != nullptr)
    {
        delete [] sounds;
    }

    sounds = new Sound[NUMSOUNDS];

    for (int i = 0; i < NUMSOUNDS; i++)
    {
        std::string path;
        path += "sound/keyclicks/keyclick";
        path += std::to_string(i + 1);
        path += ".mp3";
        *(sounds + i) = LoadSound(path.c_str());
    }


    _commands.emplace("print", ConsoleScene::print);
    _commands.emplace("ssl", ConsoleScene::ssl);
    _commands.emplace("clear", ConsoleScene::clear);


    return true;
}

int ConsoleScene::TextCallback(ImGuiInputTextCallbackData* data)
{
    // play sound
    static int prev_len = 0;
    if (prev_len != data->BufTextLen)
    {
        //std::cout << data->BufTextLen << std::endl;
        int keyclick = GetRandomValue(0, 2);
        PlaySoundMulti(*(sounds + keyclick));
    }
    prev_len = data->BufTextLen;
    return 0;
}

void ConsoleScene::SceneMain()
{
    ClearBackground(BLACK);

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(GetScreenWidth(), GetScreenHeight()));
    if (ImGui::Begin("Console", (bool*)__null, ImGuiWindowFlags_NoBackground))
    {
        ImGui::BeginChild("##ConsoleChild", ImVec2(0,
            -(ImGui::GetIO().Fonts->Fonts.front()->FontSize + 10)));
        RenderTextColored(stream);
        if (scroll_to_bottom)
        {
            ImGui::SetScrollHereY(1.0f);
            scroll_to_bottom = false;
        }
        ImGui::EndChild();
        
        ImGuiInputTextFlags textinput_flags =
            ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackAlways;
        ImGui::SetNextItemWidth(GetScreenWidth());
        if (ImGui::InputText("##ConsoleText", &curr_text, textinput_flags, ConsoleScene::TextCallback))
        {
            //Test
            std::string output = callCallback(curr_text);
            colorEncode(curr_text);
            stream << curr_text << std::endl << output << std::endl;
            curr_text = "";
            scroll_to_bottom = true;
            ImGui::SetKeyboardFocusHere(-1);
        }

        ImGui::PopStyleVar();
    }
    ImGui::End();
    
}
