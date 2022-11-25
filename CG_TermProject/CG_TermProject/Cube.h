#pragma once
#include "Header.h"

class Cube
{
	const glm::mat4 Unit;
	
	glm::mat4 Change;

	glm::vec3 color;
	float scaleX;
	float scaleY;
	float scaleZ;

	float PosX;
	float PosY;
	float PosZ;

	int mode;

	//color.r, color.g, color.b;

public:
	Cube(float SX, float SY, float SZ, float X, float Y, float Z);
	~Cube();
	void Update();
	void Draw();
};