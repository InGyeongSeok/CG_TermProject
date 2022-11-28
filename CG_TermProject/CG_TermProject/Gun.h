#pragma once
#include "Header.h"

class Gun
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

public:
	Gun(float SX, float SY, float SZ, float X, float Y, float Z);
	~Gun();
	void Update();
	void Draw();

};