#pragma once
#include "Animals.h"
class Sword : public Animals
{
private:
    int i;
    float rotate;
    bool isrotDirec;
public:
    Sword();
    Sword(glm::vec3 Color, int i);    //i�� ����
    ~Sword();
    void update() override;
    void BindVAO() override;
    void DrawArrays() override;
};

