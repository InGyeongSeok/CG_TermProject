#pragma once
#include "Animals.h"
class Nose : public Animals
{
public:
    Nose();
    Nose(glm::vec3 Color);
    ~Nose();

    void update() override;
    void BindVAO() override;
    void DrawArrays() override;

};
