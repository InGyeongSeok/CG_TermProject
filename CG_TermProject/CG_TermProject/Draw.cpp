#include "Draw.h"

void draw();
float circleSize = 2;

float lightPosX = 7.6;
float lightPosY = 1.0;
float lightPosZ = 0.0;
int lightcolorN = 0;
float lightRot;
float lightColorR = 1.0f;
float lightColorG = 1.0f;
float lightColorB = 1.0f;

Cat cat;
Dog dog;
Bear bear;
Hero hero(0.3,0.3,0.3,1.0,0.,10.0);

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
	glEnable(GL_CULL_FACE);     // 컬링
	glEnable(GL_LINE_SMOOTH);   // 안티 앨리어싱
	glEnable(GL_POLYGON_SMOOTH);// 안티 앨리어싱
	glShadeModel(GL_SMOOTH);    // 부드러운 음영을 수행합니다.s
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);

	glm::mat4 projection; // 원근투영

	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 35.f);
	//												화면비율, 시작좌표(카메라 바로 앞 길이), 깊이
	/*projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);*/
	unsigned int projectionLocation = glGetUniformLocation(shaderID, "projectionTransform"); //--- 투영 변환 값 설정
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));


	//projection = glm::translate(projection, glm::vec3(0.0, 0.0, 0.0)); //--- 공간을 약간 뒤로 미뤄줌
	//unsigned int projectionLocation = glGetUniformLocation(shaderID, "projectionTransform"); //--- 투영 변환 값 설정
	//glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
// 	//glm::mat4 projection = glm::mat4(1.0f);
//	projection = glm::ortho(-50.0f, 50.0f, -50.0f, 50.0f, -50.0f, 50.0f); //--- 투영 공간을 [-3, 3] 공간으로 설정
	glViewport(0, 0, width, height);

	camera();
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

	cat.draw();
	dog.draw();
	bear.draw();
	hero.Update();
	hero.Draw();

	
}




