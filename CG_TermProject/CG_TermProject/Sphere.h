#pragma once
#include "Header.h"

class Sphere{

	const glm::mat4 Unit;
	
	glm::mat4 Change;

	glm::vec3 color;
	float scale;

	float PosX;
	float PosY;
	float PosZ;

	//color.r, color.g, color.b;

public:
	Sphere(float s, float x, float y, float z);
	~Sphere();
	void Update();
	void Draw();
};