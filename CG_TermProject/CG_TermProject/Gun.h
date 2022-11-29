#pragma once
#include "Header.h"

class Gun
{
	const glm::mat4 Unit;

	glm::mat4 Change;

	glm::vec3 color;

	float PosX;
	float PosY;
	float PosZ;
	float Angle;

public:
	Gun(float X, float Y, float Z, float Angle);
	~Gun();
	void Update();
	void Draw();
	void Loction();
};