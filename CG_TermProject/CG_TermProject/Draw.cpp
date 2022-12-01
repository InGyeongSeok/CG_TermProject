#include "Draw.h"

void draw();
float circleSize = 2;
void AnimalCollideCat();
void AnimalCollideDog();
void BulletCollideCat();
bool isCollide2D(Cat r1, Gun r2);

int HerogetHP = 10;
float lightPosX = 7.0;
float lightPosY = 1.0;
float lightPosZ = 0.0;
int lightcolorN = 0;
float lightRot;
float lightColorR = 1.0f;
float lightColorG = 1.0f;
float lightColorB = 1.0f;

bool isBullet = false;
vector<Gun*> gun;

vector<Cat*> cats{ new Cat, new Cat, new Cat, new Cat, new Cat, new Cat };
vector<Dog*> dogs{ new Dog, new Dog, new Dog, new Dog, new Dog, new Dog };
Bear bear;
Hero hero(0.3, 0.3, 0.3, 0, 0.5, 10.0);
vector<Particle*> particle;
random_device rd;
default_random_engine dre(rd());
uniform_real_distribution<float> urd{ 0, 255 };


GLvoid drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�
{
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	if(lightColorR <0.35)
		glClearColor(0.f, 0.f, 0.f, 1.0f);
	else
		glClearColor(1.f, 1.f, 1.f, 1.0f);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);   //��������
	glEnable(GL_DITHER);        // ǥ���� �Ų�����
	//glEnable(GL_CULL_FACE);     // �ø�6
	glEnable(GL_LINE_SMOOTH);   // ��Ƽ �ٸ����
	glEnable(GL_POLYGON_SMOOTH);// ��Ƽ �ٸ����
	glShadeModel(GL_SMOOTH);    // �ε巯�� ������ �����մϴ�.
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);

	glm::mat4 projection; // ��������

	projection = glm::perspective(glm::radians(90.0f), (float)width / height, 0.1f, 200.0f);
	//												ȭ�����, ������ǥ(ī�޶� �ٷ� �� ����), ����
	unsigned int projectionLocation = glGetUniformLocation(shaderID, "projectionTransform"); //--- ���� ��ȯ �� ����
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glViewport(0, 0, width, height);
	camera();
	draw();
	
	

	glViewport(width / 1.26, height / 1.35, 200,200);
	projection = glm::mat4(1.0f);
	projection = glm::ortho(-13.0f, 13.0f, -13.0f, 13.0f, -13.0f, 13.0f);
	projectionLocation = glGetUniformLocation(shaderID, "projectionTransform");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
	TopView();

	//camera3D();

	draw();

	

	if (isBullet && BulletLimit == 0) {
		BulletLimit += 1;
		gun.push_back(new Gun{ cameraPos.x,cameraPos.y,cameraPos.z, TermGunDir.x,TermGunDir.y,TermGunDir.z });
	}

	glutSwapBuffers();
};

void draw() {

	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	unsigned int lightPosLocation = glGetUniformLocation(shaderID, "lightPos");      //--- lightPos �� ����: (0.0, 0.0, 5.0);
	//glUniform3f(lightPosLocation, 1, 0.0, 0.0);

	glm::vec4 tempv(lightPosX, lightPosY, lightPosZ, 1); //��ġ 
	glm::mat4 Lightrotate = glm::rotate(glm::mat4(1.f), glm::radians(lightRot), glm::vec3(0, 1, 0));

	tempv = Lightrotate * tempv;

	glUniform3f(lightPosLocation, tempv.x, tempv.y, tempv.z);

	unsigned int lightColorLocation = glGetUniformLocation(shaderID, "lightColor");   //--- lightColor �� ����: (1.0, 1.0, 1.0) ���
	glUniform3f(lightColorLocation, lightColorR, lightColorG, lightColorB);

	unsigned int aColor = glGetUniformLocation(shaderID, "objectColor");   //--- object Color�� ����: (1.0, 0.5, 0.3)�� ��
	glUniform3f(aColor, 1, 1., 1.);

	//////////////////////////////////////////////////////// 

	glBindVertexArray(crossVAO);
	aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, 0.2, 0.2, 0.2);

	glm::mat4 Tx = glm::mat4(1.0f);
	Tx = glm::translate(glm::mat4(1.0f), glm::vec3(0, -1.f, 0));
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Tx));
	glDrawArrays(GL_QUADS, 0, 4);



	for (int i = 0; i < cats.size(); ++i) {
		cats[i]->draw();
	}

	/*for (int i = 0; i < 6; ++i) {
		dogs[i]->draw();
	}*/

	//bear.draw();
	hero.Update();
	hero.Draw();
	for (int i = 0; i < 10; ++i) {
		particle.push_back(new Particle{ 0,0,0 });
	}
	for (int i = 0; i < 10; ++i) {
		particle[i]->draw();
		particle[i]->update();
	}
	
	/*for (Particle*& test : particle) {
		test->draw();
		test->update();
	}*/
	for (Gun*& gunbullet : gun) {
		gunbullet->Update();
		gunbullet->Draw();
	}

	///////////////////////////////////////////////////// test ��
	//glm::mat4 Scale = glm::mat4(1.0f); //--- �̵� ��� ����
	//glm::mat4 Change;
	//Scale = glm::scale(Scale, glm::vec3(3, 3, 3));
	//Tx = glm::translate(Unit, glm::vec3(0, -1.f, 0));
	//Change = Tx * Scale;

	//glBindVertexArray(testVAO);
	//SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	//glUniform1i(SelectColor, 1);

	//aColor = glGetUniformLocation(shaderID, "objectColor");
	//glUniform3f(aColor, 128 / 255., 245 / 255., 255 / 255.);
	//modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	//glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	//glDrawArrays(GL_TRIANGLES, 0, test.size() * 3);
	///////////////////////////////////////////////////////////////////////////
	
	glBindVertexArray(HeroHPVAO);     //���ε�
	aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, 1.0, 0.0, 0.0);

	for (int i = 0; i < hero.InfoHP(); ++i) {
		glm::mat4 Change;
		Change = Unit;
		GLuint projectionTransform = glGetUniformLocation(shaderID, "projectionTransform");
		glUniformMatrix4fv(projectionTransform, 1, GL_FALSE, glm::value_ptr(Change));
		Change = Unit;
		GLuint viewTransform = glGetUniformLocation(shaderID, "viewTransform");
		glUniformMatrix4fv(viewTransform, 1, GL_FALSE, glm::value_ptr(Change));

		glm::mat4 Scale = glm::scale(Unit, glm::vec3(0.3));
		glm::mat4 Trans = glm::translate(Unit, glm::vec3(-0.95, 0.95, 0));
		Change = Trans * Scale;
		Change = glm::translate(Unit, glm::vec3(i * 0.08f, 0, 0)) * Change;
		GLuint modelTransform = glGetUniformLocation(shaderID, "modelTransform");
		glUniformMatrix4fv(modelTransform, 1, GL_FALSE, glm::value_ptr(Change));

		glDrawArrays(GL_POLYGON, 0, 4);
	}      

}

void AnimalCollideCat() {
	for (int i = 0; i < cats.size(); ++i) {
		for (int j = i + 1; j < cats.size(); ++j) {
			float distanceX = abs(cats[i]->Position.x - cats[j]->Position.x);
			float distanceZ = abs(cats[i]->Position.z - cats[j]->Position.z);
			if (distanceX <= 0.1f) {
				cats[i]->Position.x += 0.1f;
			}
			if (distanceZ <= 0.1f) {
				cats[i]->Position.z += 0.1f;
			}
		}
	}
}

void AnimalCollideDog() {
	//for (int i = 0; i < dogs.size(); ++i) {
	//	for (int j = i; j < dogs.size(); ++j) {
	//		float distanceX = abs(dogs[i]->Position.x - dogs[j]->Position.x);
	//		float distanceZ = abs(dogs[i]->Position.z - dogs[j]->Position.z);
	//		if (distanceX <= 0.2f) {
	//			dogs[i]->Position.x += 0.2f;
	//		}
	//		if (distanceZ <= 0.2f) {
	//			dogs[i]->Position.z += 0.2f;
	//		}
	//	}
	//}
}

void BulletCollideCat() {

	for (int i = 0; i < gun.size(); ++i) {
		for (int j = 0; j < cats.size(); ++j) {
			if (isCollide2D(*cats[j], *gun[i])) {
				cats[j]->HP -= gun[i]->Damage;
				delete gun[i];
				if (0 == cats[j]->HP) {
					delete cats[j];
					cats.erase(cats.begin() + j);
					--j;
				}
				gun.erase(gun.begin() + i);
				--i;
				break;
			}

		}

	}
}

//float distanceX = abs(gun[i]->GunDir.x - cats[j]->Position.x);
//float distanceZ = abs(gun[i]->GunDir.z - cats[j]->Position.z);
//if (distanceX < 0.05 || distanceZ < 0.05) {
//	cats[j]->HP -= gun[i]->Damage;
//	delete gun[i];
//	if (0 == cats[j]->HP) {
//		delete cats[j];
//		cats.erase(cats.begin() + j);
//		--j;
//	}
//	gun.erase(gun.begin() + i);
//	--i;
//	break;
//}

bool isCollide2D(Cat r1, Gun r2)
{
	if (r1.getRight() < r2.getLeft() || r1.getLeft() > r2.getRight()) return false;
	if (r1.getFront() < r2.getBehind() || r1.getBehind() > r2.getFront()) return false;
	return true;
}



