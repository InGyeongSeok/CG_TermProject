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
	float dirX;
	float dirY;
	float dirZ;
	float startP;
	glm::vec3 GunDir;


public:
	Gun(float posX, float posY, float posZ, float dirX, float dirY, float dirZ);
	~Gun();
	void Update();
	void Draw();
	void Loction();

};