#include "Cube.h"

Cube::Cube(float SX, float SY, float SZ,float X,float Y,float Z) : Unit(1.f)
{
	random_device rd;
	default_random_engine dre(rd());
	uniform_real_distribution<float> urd{ 0, 255 };
	color = glm::vec3(urd(dre) / 255., urd(dre) / 255., urd(dre) / 255.);
	scaleX = SX;
	scaleY = SY;
	scaleZ = SZ;
	PosX = X;
	PosY = Y;
	PosZ = Z;
}

Cube::~Cube()
{

}



void Cube::Update()
{
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(scaleX, scaleY, scaleZ));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(PosX , PosY, PosZ));
	glm::mat4 AddTrans = glm::translate(Unit, glm::vec3(0., 1., 0.));
	glm::mat4 Rotate = glm::rotate(glm::mat4(1.0f), glm::radians(Rot), glm::vec3(0.0, 1.0, 0.0));

	Change = Rotate * Trans *Scale * AddTrans;


}


void Cube::Draw()
{

	glBindVertexArray(VAO);
	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, color.r, color.g, color.b);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
}

