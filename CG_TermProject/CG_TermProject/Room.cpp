#include "Room.h"


Room::~Room()
{
}

Room::Room(int room)
{
	AnimalRoom = room;
}


void Room::Update()
{

	glm::mat4 Scale;
	glm::mat4 Trans;
	if (AnimalRoom == 0) {//고양이
		Scale = glm::scale(Unit, glm::vec3(5, 30, 5));
		Trans = glm::translate(Unit, glm::vec3(-100, 29, 0));
	}
	if (AnimalRoom == 1) {//강아지
		Scale = glm::scale(Unit, glm::vec3(5, 30, 5));
		Trans = glm::translate(Unit, glm::vec3(100, 29, 0));
	}
	if (AnimalRoom == 2) {//곰
		Scale = glm::scale(Unit, glm::vec3(5, 30, 5));
		Trans = glm::translate(Unit, glm::vec3(0, 29, -100));
	}
	Change = Trans * Scale;
}


void Room::Draw()
{
	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));

	for (int i = 0; i < 6; ++i) {
		glBindTexture(GL_TEXTURE_2D, RoomTexture[AnimalRoom]);
		glDrawArrays(GL_TRIANGLES, i * 6, 6);
	}
	

}


