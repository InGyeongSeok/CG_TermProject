
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

class Tree
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;

public:

	Tree(float xpos, float ypos, float zpos);

	~Tree();
	void Update();
	void Draw();

};


#pragma once
