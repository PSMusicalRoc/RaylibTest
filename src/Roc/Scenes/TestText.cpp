#include "Scenes/TestText.h"

#include <raylib.h>
#include <imgui.h>
#include <string>
#include <sstream>

#include <iostream>
#include "Utils/ColoredText.h"

void TT::SceneMain()
{
    ClearBackground(RAYWHITE);

    ImGui::Begin("TTTest");

    RenderTextColored(stream);

    ImGui::End();
}