
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

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


