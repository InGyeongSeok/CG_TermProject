#include "Hero.h"

float HeroMovX;
float HeroMovY;
float HeroMovZ;
float MovX;
float MovZ;

float HeroLocationX{};
float HeroLocationZ{};
CatAttack catattack[6];
DogAttack dogattack[6];
BearAttack bearattack;

bool jumpUp = true;

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
	HP = 100;

}

Hero::~Hero()
{
	
}

void Hero::damage()
{

	HP = 100;
	lightColorG = 1.0;
	lightColorB = 1.0;
	for (int i = 0; i < 6; ++i) {
		HP -= (catattack[i].AttackCount) * 10 / 24;
		lightColorG -= catattack[i].AttackCount * 0.1f/24.;
		lightColorB -= catattack[i].AttackCount * 0.1f/24.;

		HP -= (dogattack[i].AttackCount) * 20 / 24;
		lightColorG -= dogattack[i].AttackCount * 0.2f / 24.;
		lightColorB -= dogattack[i].AttackCount * 0.2f / 24.;
	}


	HP -= (bearattack.AttackCount) * 30 / 24;
	lightColorG -= bearattack.AttackCount * 0.3f / 24.;
	lightColorB -= bearattack.AttackCount * 0.3f / 24.;


	if (lightColorG < 0.0) {
		lightColorB = 0;
		lightColorG = 0;
		lightColorR = 0;
	}
}



int Hero::InfoHP() {
	return HP/10;
}

void Hero::Update()
{ 
	// 0, 0.5, 20.0
	damage();
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(scaleX, scaleY, scaleZ));
	glm::mat4 Trans;
	
		Trans = glm::translate(Unit, glm::vec3(PosX + HeroMovX, PosY + HeroMovY, PosZ + HeroMovZ));
	glm::mat4 AddTrans = glm::translate(Unit, glm::vec3(0., 1., 0.));
	Change = Trans * Scale * AddTrans;
	
}

void Hero::Jump()
{
	if (isJump) {
		if (jumpUp) {
			HeroMovY += 0.1f;
			cameraJump +=0.1f;
			if (HeroMovY >= 1) {
				jumpUp = false;
			}
		}
		else {
			HeroMovY -= 0.1f;
			cameraJump -= 0.1f;

			if (HeroMovY <= 0.f) {
				isJump = false;
			}
		}
	}
	
	
}

void Hero::Draw()
{

	glBindVertexArray(VAO);
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform4f(aColor, color.r, color.g, color.b,1.0);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);


}

void Hero::location()
{
	HeroLocationX = PosX + HeroMovX;
	HeroLocationZ = PosZ + HeroMovZ;
}