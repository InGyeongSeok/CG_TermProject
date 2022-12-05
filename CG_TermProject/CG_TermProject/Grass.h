
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

class Grass
{
	glm::vec3 Color;
	glm::mat4 Change;
	float Size;
	float Xpos;
	float Ypos;
	float Zpos;

public:

	Grass();

	~Grass();
	void Update();
	void Draw();

};


