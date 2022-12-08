#include "Hero.h"

float HeroMovY;
float MovX;
float MovZ;
bool catlive = false;
bool doglive = false;
bool bearlive = false;

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
	color = glm::vec3(255 / 255., 255 / 255., 255 / 255.);
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
	
	cout << "PosX -" << PosX << endl;
	cout << "PosZ -" << PosZ << endl;

	damage();
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(scaleX, scaleY, scaleZ));
	glm::mat4 Trans;
	
		Trans = glm::translate(Unit, glm::vec3(PosX, PosY + HeroMovY, PosZ ));
		
		if (PosZ < -20 && catdead ==0) {
			PosX = -100;
			PosZ = 0;
			catlive = true;
			bearlive = false;
			doglive = false;

			CarX = -100;
			CarY = 1.0;
			CarZ = 0.0;

			CarDX = -100;
			CarDY = 0.0;
			CarDZ = 0.0;
			ortho = 5.0;

			lightPosX = -100;
			lightPosY = 15.0;
			lightPosZ = 0;
		}
		if (PosZ < -7 && catdead == 6) {
			PosX = 100;
			PosZ = 0;
			doglive = true;
			catlive = false;
			bearlive = false;
			CarX = 100;
			CarY = 1.0;
			CarZ = 0.0;

			CarDX = 100;
			CarDY = 0.0;
			CarDZ = 0.0;
			ortho = 5.0;

			lightPosX = 100;
			lightPosY = 15.0;
			lightPosZ = 0;

			catdead++;
		}
		if (PosZ < -7 && dogdead == 6) {
			PosX = 0;
			PosZ = -100;
			dogdead++;

			doglive = false;
			bearlive = true;
			catlive = false;
			CarX = 0.0;
			CarY = 1.0;
			CarZ = -100.0;

			CarDX = 0.0;
			CarDY = 0.0;
			CarDZ = -100.0;
			ortho = 5.0;

			lightPosX = 0;
			lightPosY = 15.0;
			lightPosZ = -100;
		}
		
	glm::mat4 AddTrans = glm::translate(Unit, glm::vec3(0., 1., 0.));
	Change = Trans * Scale * AddTrans;
	if(catlive && catdead <6)
		HeroVSCat();
		
	if(doglive && dogdead < 6)
		HeroVSDog();
		
	if(bearlive)
		HeroVSBear();
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
	HeroLocationX = PosX;
	HeroLocationZ = PosZ;
}

void Hero::isW()
{
	PosZ -= 0.075 * glm::cos(glm::radians(VAngleY));
	PosX += 0.075 * glm::sin(glm::radians(VAngleY));
}

void Hero::isA()
{


	PosZ -= 0.075 * glm::sin(glm::radians(VAngleY));
	PosX -= 0.075 * glm::cos(glm::radians(VAngleY));

}

void Hero::isS()
{
	PosZ += 0.075 * glm::cos(glm::radians(VAngleY));
	PosX -= 0.075 * glm::sin(glm::radians(VAngleY));
}

void Hero::isD()
{
	PosZ  += 0.075 * glm::sin(glm::radians(VAngleY));
	PosX  += 0.075 * glm::cos(glm::radians(VAngleY));
}

float Hero::getLeft()
{
	return PosX - 0.12f;
}

float Hero::getRight()
{
	return PosX + 0.12f;
}

float Hero::getBehind()
{
	return PosZ - 0.12f;
}

float Hero::getFront()
{
	return PosZ + 0.12f;
}