
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

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

