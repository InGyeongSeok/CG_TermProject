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


GLvoid drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�
{
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	glClearColor(1.f, 1.f, 1.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);   //��������
	glEnable(GL_DITHER);        // ǥ���� �Ų�����
	//glEnable(GL_CULL_FACE);     // �ø�6
	glEnable(GL_LINE_SMOOTH);   // ��Ƽ �ٸ����
	glEnable(GL_POLYGON_SMOOTH);// ��Ƽ �ٸ����
	glShadeModel(GL_SMOOTH);    // �ε巯�� ������ �����մϴ�.s
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);

	glm::mat4 projection; // ��������

	projection = glm::perspective(glm::radians(90.0f), (float)width / height, 0.1f, 200.0f);
	//												ȭ�����, ������ǥ(ī�޶� �ٷ� �� ����), ����
	/*projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);*/
	unsigned int projectionLocation = glGetUniformLocation(shaderID, "projectionTransform"); //--- ���� ��ȯ �� ����
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glViewport(0, 0, width, height);
	camera();

	/// XYZ ��

	glBindVertexArray(crossVAO);     //���ε�
	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, 0.2, 0.2, 0.2);

	glm::mat4 Tx = glm::mat4(1.0f); //--- �̵� ��� ����
	Tx = glm::translate(glm::mat4(1.0f), glm::vec3(0, -1.f, 0));
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Tx));
	glDrawArrays(GL_QUADS, 0, 4);         //�׸���
	
	draw();
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



