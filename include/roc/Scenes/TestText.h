#ifndef _ROC_TEST_H_
#define _ROC_TEST_H

#include "Scene.h"
#include <sstream>
#include "Utils/ColoredText.h"

class TT : public Scene
{
private:
    std::stringstream stream;
public:
    TT()
        :Scene("TT")
    {
        stream << "Hey All, " << UTILITYCHAR << "[0,1,.4,1]Scott Here\n"
            << UTILITYCHAR << "[0, 1, 1, 1]timbi>";
    }
    void SceneMain() override;
};

#endif