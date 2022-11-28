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


class Bear
{
	Head head;
	Nose nose;
	Body body;
	Body bodyf;
	Arm armL;
	Arm armR;
	Leg legL;
	Leg legR;
	Eyes eyesR;
	Eyes eyesL;
	Ear earL;
	Ear earR;
	Sword swordR;
	Sword swordL;
	Beard eyebrowL;
	Beard eyebrowR;
	
	
	glm::vec3 Position;
	float Direction;

public:
	Bear();
	~Bear();

	void draw();
	void update(unsigned char key);
	void damage();
	float getLeft();
	float getRight();
	float getBehind();
	float getFront();
	float getBottom();
	float getTop();
};

