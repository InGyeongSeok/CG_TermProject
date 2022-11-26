#pragma once
#include "Animals.h"
class Ear : public Animals
{
    int i;
public:
    Ear();
    Ear(glm::vec3 Color, int i);
    ~Ear();

    void update() override;
    void BindVAO() override;
    void DrawArrays() override;

};
