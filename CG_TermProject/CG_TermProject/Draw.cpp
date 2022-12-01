#include "Draw.h"

void draw();
float circleSize = 2;
void AnimalCollideCat();
void AnimalCollideDog();
void BulletCollideCat();
bool isCollide2D(Cat r1, Gun r2);


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

vector<Cat*> cats{new Cat, new Cat, new Cat, new Cat, new Cat, new Cat};
vector<Dog*> dogs{new Dog, new Dog, new Dog, new Dog, new Dog, new Dog};
Bear bear;
Hero hero(0.3,0.3,0.3,1,0.5,10.0);

random_device rd;
default_random_engine dre(rd());
uniform_real_distribution<float> urd{ 0, 255 };


GLvoid drawScene() //--- 콜백 함수: 그리기 콜백 함수
{
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	glClearColor(1.f, 1.f, 1.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);   //은면제거
	glEnable(GL_DITHER);        // 표면을 매끄럽게
	//glEnable(GL_CULL_FACE);     // 컬링6
	glEnable(GL_LINE_SMOOTH);   // 안티 앨리어싱
	glEnable(GL_POLYGON_SMOOTH);// 안티 앨리어싱
	glShadeModel(GL_SMOOTH);    // 부드러운 음영을 수행합니다.
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);

	glm::mat4 projection; // 원근투영

	projection = glm::perspective(glm::radians(90.0f), (float)width / height, 0.1f, 200.0f);
	//												화면비율, 시작좌표(카메라 바로 앞 길이), 깊이
	/*projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);*/
	unsigned int projectionLocation = glGetUniformLocation(shaderID, "projectionTransform"); //--- 투영 변환 값 설정
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glViewport(0, 0, width, height);
	camera();

	/// XYZ 선

	glBindVertexArray(crossVAO);     //바인드
	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, 0.2, 0.2, 0.2);

	glm::mat4 Tx = glm::mat4(1.0f); //--- 이동 행렬 선언
	Tx = glm::translate(glm::mat4(1.0f), glm::vec3(0, -1.f, 0));
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Tx));
	glDrawArrays(GL_QUADS, 0, 4);         //그리기


	if (isBullet&&BulletLimit==0) {
		BulletLimit += 1;
		gun.push_back(new Gun{ cameraPos.x,cameraPos.y,cameraPos.z, TermGunDir.x,TermGunDir.y,TermGunDir.z });
	}
	
	draw();
	glutSwapBuffers();
};

void draw() {

	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	unsigned int lightPosLocation = glGetUniformLocation(shaderID, "lightPos");      //--- lightPos 값 전달: (0.0, 0.0, 5.0);
	//glUniform3f(lightPosLocation, 1, 0.0, 0.0);

	glm::vec4 tempv(lightPosX, lightPosY, lightPosZ, 1); //위치 
	glm::mat4 Lightrotate = glm::rotate(glm::mat4(1.f), glm::radians(lightRot), glm::vec3(0, 1, 0));

	tempv = Lightrotate * tempv;

	glUniform3f(lightPosLocation, tempv.x, tempv.y, tempv.z);

	unsigned int lightColorLocation = glGetUniformLocation(shaderID, "lightColor");   //--- lightColor 값 전달: (1.0, 1.0, 1.0) 백색
	glUniform3f(lightColorLocation, lightColorR, lightColorG, lightColorB);

	unsigned int aColor = glGetUniformLocation(shaderID, "objectColor");   //--- object Color값 전달: (1.0, 0.5, 0.3)의 색
	glUniform3f(aColor, 1., 1., 1.);


	for (int i = 0; i < cats.size(); ++i) {
		cats[i]->draw();
	}

	/*for (int i = 0; i < 6; ++i) {
		dogs[i]->draw();
	}*/

	//bear.draw();
	hero.Update();
	hero.Draw();

	for (Gun*& gunbullet : gun) {
		gunbullet->Update();
		gunbullet->Draw();
	}
	

	glm::mat4 Scale = glm::mat4(1.0f); //--- 이동 행렬 선언
	glm::mat4 Tx = glm::mat4(1.0f); //--- 이동 행렬 선언
	glm::mat4 Change;
	Scale = glm::scale(Scale, glm::vec3(3, 3,3));
	Tx = glm::translate(glm::mat4(1.0f), glm::vec3(0, -1.f, 0));
	Change =Tx*Scale;

	glBindVertexArray(testVAO);
	SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, 128/255., 245/255., 255/255.);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, test.size() * 3);
	
}

void AnimalCollideCat() {  
	for (int i = 0; i < cats.size(); ++i) {
		for (int j = i+1; j < cats.size(); ++j) {
			float distanceX = abs(cats[i]->Position.x - cats[j]->Position.x);
			float distanceZ = abs(cats[i]->Position.z - cats[j]->Position.z);
			if (distanceX <= 0.1f) {
				cats[i]->Position.x += 0.1f;
			}
			if (distanceZ<=0.1f) {
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



