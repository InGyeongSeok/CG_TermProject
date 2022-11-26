#pragma once
#include "Animals.h"
class Arm : public Animals
{
private:
    int i;
    float rotate;
    bool isrotDirec;
public:
    Arm();
    Arm(glm::vec3 Color, int i);    //i´Â ¹æÇâ
    ~Arm();

    void update() override;
    void BindVAO() override;
    void DrawArrays() override;

};

