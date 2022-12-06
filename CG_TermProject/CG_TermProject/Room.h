
#pragma once
#include "Header.h"

//좌표 XYZ / 스케일 / 색상 

class Room
{
	glm::mat4 Change;
	int AnimalRoom;

public:

	Room(int room);

	~Room();
	void Update();
	void Draw();

};


