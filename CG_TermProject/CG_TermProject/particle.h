#pragma once
#include "Head.h"


class Particle {
	float Xpos;
	float Ypos;
	float Zpos; 
	glm::mat4 Change;
	glm::vec3 color;
	int life = 10;

public:
	Particle(float Xpos, float Ypos, float Zpos);
	~Particle();

	void draw();
	void update();
};

