#include "Gun.h"



Gun::Gun(float X, float Y, float Z) : Unit(1.f)
{
	random_device rd;
	default_random_engine dre(rd());
	uniform_real_distribution<float> urd{ 0, 255 };
	color = glm::vec3(urd(dre) / 255., urd(dre) / 255., urd(dre) / 255.);

	PosX = X;
	PosY = Y;
	PosZ = Z;

}

Gun::~Gun()
{

}



void Gun::Update()
{
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(0.01, 0.01, 0.01));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(PosX, PosY, PosZ));
	glm::mat4 AddTrans = glm::translate(Unit, glm::vec3(0., 1., 0.));
	Change = Trans * Scale * AddTrans;
}


void Gun::Draw()
{

	glBindVertexArray(VAO);
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, color.r, color.g, color.b);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
}

void Gun::Loction()
{
	;
}