
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

class Gameover
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;

	float Direction;
	
public:


	Gameover(float Xpos, float Zpos);

	~Gameover();
	void Update();
	void Draw();

};

