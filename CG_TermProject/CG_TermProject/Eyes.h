#pragma once
#include "Animals.h"
class Eyes : public Animals
{
    int i;
public:
    Eyes();
    Eyes(glm::vec3 Color, int i);
    ~Eyes();

    void update() override;
    void BindVAO() override;
    void DrawArrays() override;

};
