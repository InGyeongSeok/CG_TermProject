
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

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

