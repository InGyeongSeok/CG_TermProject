#pragma once
#include "Animals.h"
class Body : public Animals
{
public:
    Body();
    Body(glm::vec3 Color);
    ~Body();

    void update() override;
    void BindVAO() override;
    void DrawArrays() override;

};

