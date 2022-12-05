#include "Grass.h"


Grass::~Grass()
{
}

Grass::Grass()
{
	random_device rd;
	default_random_engine dre(rd());
	uniform_real_distribution<float> urd{ 0.5f, 1.f };
	uniform_real_distribution<float> XZ{ -50.f,50.f };
	uniform_real_distribution<float> size{ 0.005,0.01f };
	Xpos = XZ(dre);
	Zpos = XZ(dre);
	
	Color = glm::vec3(0, 1,0);
	
}


void Grass::Update()
{
	glm::mat4 Rotate = glm::rotate(Unit, glm::radians(-30.f), glm::vec3(0.f, 0, 1));
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(0.005, 0.005, 0.005));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(0,2, 0));

	Change = Trans  * Rotate * Scale;
}


void Grass::Draw()
{
	glBindVertexArray(GrassVAO);
	GLuint Color = glGetUniformLocation(shaderID, "objectColor");
	glUniform4f(Color, this->Color.r, this->Color.g, this->Color.b, 1.0);

	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change)); //--- modelTransform 변수에 변환
	glDrawArrays(GL_TRIANGLES, 0, vertex4.size() * 3);

}


