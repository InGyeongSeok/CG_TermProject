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

void camera() {
   
	cameraPos = glm::vec3(carAddX +0, carAddY + cameraJump, carAddZ);     
	if (bearlive) {
		if (third) {
			carAddX = 0;
			carAddZ = -100;
			third = false;
		}
		if (-5 > carAddX)
			carAddX += 0.5;
		if (5 < carAddX)
			carAddX -= 0.5;
		if (-105 > carAddZ)
			carAddZ += 0.5;
		if (-95 < carAddZ)
			carAddZ -= 0.5;
	}

	else if (doglive && dogdead < 6) {
		if (second) {
			carAddX = 100;
			carAddZ = 0;
			second = false;
		}
		if (95 > carAddX)
			carAddX += 0.5;
		if (105 < carAddX)
			carAddX -= 0.5;
		if (-5 > carAddZ)
			carAddZ += 0.5;
		if (+5 < carAddZ)
			carAddZ -= 0.5;
	}
	else if (catlive && catdead < 6) {
		if (first) {
			carAddX = -100;
			carAddZ = 0;
			first = false;
		}
		if (-105 > carAddX)
			carAddX += 0.5;
		if (-95 < carAddX)
			carAddX -= 0.5;
		if (-5 > carAddZ)
			carAddZ += 0.5;
		if (+5 < carAddZ)
			carAddZ -= 0.5;
		
	}
	
	glm::mat4 VAngleY_Rot = glm::rotate(glm::mat4(1.0f), glm::radians(-VAngleY), glm::vec3(0.0, 1.0, 0.0)); 
	glm::mat4 VAngleX_Rot = glm::rotate(glm::mat4(1.0f), glm::radians(-VAngleX), glm::vec3(1.0, 0.0, 0.0)); 

	glm::vec3 CDir(0.f, 0.f, -10.f);
	CDir = VAngleY_Rot * VAngleX_Rot * glm::vec4(CDir, 1.f);
	CDir.x += 1.f;

	glm::vec3 cameraDirection(cameraPos + CDir);							
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);                    
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
	glm::vec3 cameraPos = glm::vec3(0.f, 1.f, 0);
	glm::vec3 cameraDirection = glm::vec3(0.f, 0.0f, 0.0f);
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