
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

class Castle
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;
	
public:

	Castle();

	~Castle();
	void Update();
	void Draw();

};

