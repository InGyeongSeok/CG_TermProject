#include "Hero.h"

float HeroMovX;
float HeroMovY;
float HeroMovZ;

float HeroLocationX{};
float HeroLocationZ{};

	//color.r, color.g, color.b;
Hero::Hero(float SX, float SY, float SZ, float X, float Y, float Z) : Unit(1.f)
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

Hero::~Hero()
{

}

void Hero::damage()
{
	HP -= 0.07;
	cout << "HP - " << HP << endl;
	if (HP < 0 ) {
		cout << "DEAD" << endl;
	}
}

void Hero::Update()
{
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(scaleX, scaleY, scaleZ));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(PosX+HeroMovX, PosY+ HeroMovY, PosZ+ HeroMovZ));
	glm::mat4 AddTrans = glm::translate(Unit, glm::vec3(0., 1., 0.));
	Change = Trans * Scale * AddTrans;
}


void Hero::Draw()
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

void Hero::location()
{
	HeroLocationX = PosX + HeroMovX;
	HeroLocationZ = PosZ + HeroMovZ;
}