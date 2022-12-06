#pragma once
#include "Header.h"
#include "CatAttack.h"
#include "DogAttack.h"
#include "BearAttack.h"

extern CatAttack catattack[6];
extern DogAttack dogattack[6];
extern BearAttack bearattack;

class Hero
{
	const glm::mat4 Unit;

	glm::mat4 Change;

	glm::vec3 color;
	float scaleX;
	float scaleY;
	float scaleZ;
	int HP;
	float PosX;
	float PosY;
	float PosZ;

public:
	Hero(float SX, float SY, float SZ, float X, float Y, float Z);
	~Hero();
	void Jump();
	void damage();
	void Update();
	void Draw();
	int InfoHP();
	void location();
};