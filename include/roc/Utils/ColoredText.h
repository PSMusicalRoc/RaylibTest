#ifndef _ROC_UTILS_COLORED_TEXT_H_
#define _ROC_UTILS_COLORED_TEXT_H_

#include <imgui.h>

#include <string>
#include <sstream>

#define UTILITYCHAR char(0x1D) // Group Separator

void _interpretColoredText(std::string& str, ImVec4& curr_color);

void RenderTextColored(std::stringstream& in_stream);

#endif