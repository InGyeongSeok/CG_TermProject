
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

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

