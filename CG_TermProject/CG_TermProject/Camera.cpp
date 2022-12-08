#include "Camera.h"
bool first = true;
bool second = true;
bool third = true;
GLuint shaderID;

float carY;
float carAddX;
float carAddY;
float carAddZ{10};
float VAngleX;
float VAngleY;
float cameraJump{};

glm::vec3 TermGunDir;
glm::vec3 cameraPos;


float CarX = 0.0;
float CarY = 1.0;
float CarZ = 0.0;

float CarDX = 0.0;
float CarDY = 0.0;
float CarDZ = 0.0;

void camera() {

	//glm::vec3 cameraPos(carAddX + 1, carAddY, carAddZ + 10);      //--- 카메라 위치 (어디서 볼건지)
	cameraPos = glm::vec3(carAddX +0, carAddY + cameraJump, carAddZ);      //--- 카메라 위치 (어디서 볼건지)
	if (bearlive) {
		if (third) {
			carAddX = 0;
			carAddZ = -100;
			third = false;
		}
		if (-5 > carAddX)
			carAddX += 1.0;
		if (5 < carAddX)
			carAddX -= 1.0;
		if (-105 > carAddZ)
			carAddZ += 1.0;
		if (-95 < carAddZ)
			carAddZ -= 1.0;
		//bearlive = false;
	}
	else if (doglive) {
		if (second) {
			carAddX = 100;
			carAddZ = 0;
			second = false;
		}
		if (95 > carAddX)
			carAddX += 1.0;
		if (105 < carAddX)
			carAddX -= 1.0;
		if (-5 > carAddZ)
			carAddZ += 1.0;
		if (+5 < carAddZ)
			carAddZ -= 1.0;
		//doglive = false;
	}
	else if (catlive) {
		if (first) {
			carAddX = -100;
			carAddZ = 0;
			first = false;
		}
		if (-105 > carAddX)
			carAddX += 1.0;
		if (-95 < carAddX)
			carAddX -= 1.0;
		if (-5 > carAddZ)
			carAddZ += 1.0;
		if (+5 < carAddZ)
			carAddZ -= 1.0;
		//catlive = false;
	}
	
	//cameraPos = glm::vec3(carAddX + 0, carAddY + cameraJump, carAddZ + 0);
	glm::mat4 VAngleY_Rot = glm::rotate(glm::mat4(1.0f), glm::radians(-VAngleY), glm::vec3(0.0, 1.0, 0.0)); //y?
	glm::mat4 VAngleX_Rot = glm::rotate(glm::mat4(1.0f), glm::radians(-VAngleX), glm::vec3(1.0, 0.0, 0.0)); // x

	glm::vec3 CDir(0.f, 0.f, -10.f);
	CDir = VAngleY_Rot * VAngleX_Rot * glm::vec4(CDir, 1.f);
	CDir.x += 1.f;

	glm::vec3 cameraDirection(cameraPos + CDir);							//--- 카메라 바라보는 방향 (어디볼건지 하면될듯)
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);                     //--- 카메라 위쪽 방향->벡터임(방향만) (음수하면 화면 상하거꾸로보임)
	cameraDirection.y -= 0.5f;
	cameraPos.y -= 0.5f;
	glm::mat4 view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	TermGunDir = normalize(cameraDirection - cameraPos);

	unsigned int viewLocation = glGetUniformLocation(shaderID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);

	unsigned int viewPosLocation = glGetUniformLocation(shaderID, "viewPos");
	glUniform3f(viewPosLocation, cameraPos.x, cameraPos.y, cameraPos.z);

}

void TopView()
{
	glm::vec3 cameraPos = glm::vec3(CarX, CarY, CarZ);
	glm::vec3 cameraDirection = glm::vec3(CarDX, CarDY, CarDZ);
	glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::mat4 view = glm::mat4(1.0f);


	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	unsigned int viewLocation = glGetUniformLocation(shaderID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
}

void camera3D() {
	glm::vec3 cameraPos = glm::vec3(0.f, 5.f,5.f);
	glm::vec3 cameraDirection = glm::vec3(0.f, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 view = glm::mat4(1.0f);


	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	unsigned int viewLocation = glGetUniformLocation(shaderID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));

}