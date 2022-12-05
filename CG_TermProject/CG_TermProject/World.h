
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

class World
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;

public:

	World(float xpos, float ypos, float zpos);

	~World();
	void Update();
	void Draw();

};


