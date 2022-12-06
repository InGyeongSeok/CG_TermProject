
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

class CastleObj
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;

public:

	CastleObj();

	~CastleObj();
	void Update();
	void Draw();

};

