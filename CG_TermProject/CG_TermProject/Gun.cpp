#include "Gun.h"

Gun::Gun(float posX, float posY, float posZ,float dirX,float dirY,float dirZ) : Unit(1.f),PosX(posX),PosY(posY),PosZ(posZ),
dirX(dirX), dirY(dirY), dirZ(dirZ)
{
	startP = 1.2;
	color = glm::vec3(1,1,0);
	

}

Gun::~Gun()
{

}

void Gun::Update()
{

	startP += 0.1;
	GunDir = glm::vec3(dirX * startP, dirY * startP, dirZ * startP) + glm::vec3(PosX, PosY, PosZ);
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(0.01, 0.01, 0.01));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(GunDir.x, GunDir.y, GunDir.z));
	Change = Trans * Scale ;

}


void Gun::Draw()
{

	glBindVertexArray(sphereVAO);
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, color.r, color.g, color.b);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
}

void Gun::Loction()
{

}