
#pragma once

#include "Head.h"
#include "Nose.h"
#include "Body.h"
#include "Arm.h"
#include "Leg.h"
#include "Eyes.h"
#include "Ear.h"
#include "Beard.h"
#include "sword.h"


class Dog
{
	Head head;
	Nose nose;
	Body body;
	Arm armL;
	Arm armR;
	Leg legL;
	Leg legR;
	Eyes eyesL;
	Eyes eyesR;
	Ear earL;
	Ear earR;
	Beard beardvertical;
	Beard beardhorizon;
	Sword swordR;
	Sword swordL;


	glm::vec3 Position;
	float Direction;

public:
	Dog();
	~Dog();

	void draw();
	void update(unsigned char key);

	float getLeft();
	float getRight();
	float getBehind();
	float getFront();
	float getBottom();
	float getTop();
};

