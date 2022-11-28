#include "Camera.h"


GLuint shaderID;

float carY;
float carAddX;
float carAddY;
float carAddZ;
float VAngleX;
float VAngleY;

void camera() {
	glm::vec3 CPos(carAddX+1, -0.5+carAddY , carAddZ + 10);
	glm::vec3 CDir(1.f + carAddX, -0.5f+  carAddY, 0.0f + carAddZ);

	glm::mat4 VAngleY_Rot = glm::rotate(glm::mat4(1.0f), glm::radians(VAngleY), glm::vec3(0.0, 1.0, 0.0)); 
	glm::mat4 VAngleX_Rot = glm::rotate(glm::mat4(1.0f), glm::radians(VAngleX), glm::vec3(1.0, 0.0, 0.0)); 
	
	glm::vec3 cameraPos = glm::vec3(CPos.x, CPos.y, CPos.z);      
	glm::vec3 cameraDirection = glm::vec3(CDir.x, CDir.y, CDir.z);              
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);                    

	glm::mat4 view = VAngleX_Rot * VAngleY_Rot * glm::lookAt(cameraPos, cameraDirection, cameraUp);

	unsigned int viewLocation = glGetUniformLocation(shaderID, "viewTransform"); 
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);

	unsigned int viewPosLocation = glGetUniformLocation(shaderID, "viewPos");      
	glUniform3f(viewPosLocation, cameraPos.x, cameraPos.y, cameraPos.z);


}


//void onecamera() {
//	glm::vec3 cameraPos;
//	glm::mat4 orbitRot = glm::mat4(1.0f);
//	glm::mat4 orbitRot1 = glm::mat4(1.0f);
//	glm::mat4 view = glm::mat4(1.0f);
//	
//	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); // ���� 
//
//	glm::vec3 cameraDirection = glm::vec3(0.f+ AddX, 3.0f+ AddY, 0.0f+ AddZ); // ī�޶� ���󺸱�
//	orbitRot = glm::rotate(orbitRot, glm::radians(orbit), glm::vec3(0.0, 1.0, 0.0));
//	orbitRot1 = glm::rotate(orbitRot1, glm::radians(orbit1), glm::vec3(1.0, 0.0, 0.0));
//
//	cameraPos = glm::vec3(0.f+ AddX, 3.f+AddY, 29.f+AddZ); //ī�޶� ��ġ
//	view = orbitRot1 * orbitRot * glm::lookAt(cameraPos, cameraDirection, cameraUp);
//	unsigned int viewLocation = glGetUniformLocation(shaderID, "viewTransform"); //--- ���� ��ȯ ����
//	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
//
//}
//
//
////�̴ϸ�
//void camera2() {
//	glm::vec3 cameraPos;
//
//	cameraPos = glm::vec3(0.f, 30.f, 0.f); //ī�޶� ��ġ
//	glm::vec3 cameraDirection = glm::vec3(0.f, 0.0f, 0.0f); // ī�޶� ���󺸱�
//	glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, -1.0f); // ���� 
//	glm::mat4 view = glm::mat4(1.0f);
//	glm::mat4 orbitRot = glm::mat4(1.0f);
//
//	if (Ybutton || ybutton) { // ����
//
//		view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
//		view = glm::rotate(view, glm::radians(carY), glm::vec3(0.0, 1.0, 0.0));
//	}
//	else {
//		view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
//	}
//	unsigned int viewLocation = glGetUniformLocation(shaderID, "viewTransform"); //--- ���� ��ȯ ����
//	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
//}
