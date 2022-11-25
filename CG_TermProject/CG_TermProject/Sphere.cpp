#include "Sphere.h"
float lightRot;
float Rot;

Sphere::Sphere(float s,float x, float y, float z) : Unit(1.f)
{
	
	//random_device rd;
	//default_random_engine dre(rd());
	//uniform_real_distribution<float> urd{ 0, 255 };
	color = glm::vec3(255/ 255., 255 / 255., 255 / 255.);
	scale = s;
	PosX = x;
	PosY = y;
	PosZ = z;
}

Sphere::~Sphere()
{

}

void Sphere::Update()
{
	glm::mat4 Rotate = glm::rotate(glm::mat4(1.0f), glm::radians(lightRot), glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(scale, scale, scale));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(PosX , PosY, PosZ));
	Change = Rotate *Trans * Scale;

}


void Sphere::Draw()
{

	glBindVertexArray(sphereVAO);
	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, color.r, color.g, color.b);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
}

