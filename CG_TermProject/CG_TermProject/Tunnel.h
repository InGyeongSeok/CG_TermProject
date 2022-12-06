#pragma once
#include "Header.h"


class Tunnel
{
	glm::mat4 Change;
	float Xpos;
	float Zpos;


public:

	Tunnel(double xPos, double zPos);

	~Tunnel();
	void Update();
	void Draw();

};


