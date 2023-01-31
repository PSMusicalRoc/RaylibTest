#include "Utils/ColoredText.h"

void _interpretColoredText(std::string& str, ImVec4& curr_color)
{
    std::string out;
    bool should_stop = false;
    while (!should_stop)
    {
        size_t find = str.find(UTILITYCHAR + std::string("["));
        if (find == str.npos)
        {
            should_stop = true;
            ImGui::TextColored(curr_color, str.c_str());
            continue;
        }
        out = str.substr(0, find);
        str = str.substr(find + 2);
        //ImVec4 copy = ImVec4(curr_color);
        ImGui::TextColored(curr_color, out.c_str());
        ImGui::SameLine();

        //std::string color_str = str.substr(1);
        size_t color_str_index = str.find("]");
        std::string color_str = str.substr(0, color_str_index);
        //size_t substr_index = str.find("]");
        str = str.substr(color_str_index + 1);

        std::stringstream stream_in(color_str);
        std::string in;
        int i = 0;
        float *color_vals = new float[4];
        for (i = 0; i < 4; i++)
        {
            std::getline(stream_in, in, ',');
            color_vals[i] = std::stof(in); 
        }

        curr_color = ImVec4(color_vals[0], color_vals[1], color_vals[2], color_vals[3]);
        delete [] color_vals;
    }
}

void RenderTextColored(std::stringstream& in_stream)
{
    ImVec4 curr_color = ImGui::GetStyleColorVec4(ImGuiCol_Text);
    std::string str_to_break = in_stream.str();
    std::string out;
    bool should_stop = false;
    while (!should_stop)
    {
        size_t find = str_to_break.find("\n");
        if (find == str_to_break.npos)
        {
            should_stop = true;

            _interpretColoredText(str_to_break, curr_color);

            continue;
        }
        out = str_to_break.substr(0, find);
        str_to_break = str_to_break.substr(find + 1);
        _interpretColoredText(out, curr_color);
    }
}