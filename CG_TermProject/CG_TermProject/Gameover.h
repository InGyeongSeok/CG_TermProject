
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

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

