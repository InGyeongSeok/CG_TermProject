#pragma once
#include "Animals.h"


class Head : public Animals
{
public:
    Head();
    Head(glm::vec3 Color);
    ~Head();
    
    void update() override;
    void BindVAO() override;
    void DrawArrays() override;

};

