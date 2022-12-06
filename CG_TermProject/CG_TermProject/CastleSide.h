
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

class CastleSide
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;
	

public:

	CastleSide();

	~CastleSide();
	void Update();
	void Draw();

};

