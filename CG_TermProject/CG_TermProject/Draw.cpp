#include "Draw.h"

void draw();
float circleSize = 2;
void AnimalCollide();
float lightPosX = 7.0;
float lightPosY = 1.0;
float lightPosZ = 0.0;
int lightcolorN = 0;
float lightRot;
float lightColorR = 1.0f;
float lightColorG = 1.0f;
float lightColorB = 1.0f;

Cat* cats = new Cat[6];
Dog dog;
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
	glShadeModel(GL_SMOOTH);    // 부드러운 음영을 수행합니다.s
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


	for (int i = 0; i < 6; ++i) {
		cats[i].draw();
	}


	//dog.draw();
	//bear.draw();
	hero.Update();
	hero.Draw();

	if (commandGun) {
		Gun gun(1, 0.0,7);
		gun.Update();
		gun.Draw();

	}
	
	
}

void AnimalCollide() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5 - i; ++j) {
			float distanceX = abs(cats[j].Position.x - cats[j + 1].Position.x);
			float distanceZ = abs(cats[j].Position.z - cats[j + 1].Position.z);
			if (distanceX <= 0.2f) {
				cats[j].Position.x += 0.2f;
			}
			if (distanceZ<=0.2f) {
				cats[j].Position.z += 0.2f;
			}
		}
	}
}



