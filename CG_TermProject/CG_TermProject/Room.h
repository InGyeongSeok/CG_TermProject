
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

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


