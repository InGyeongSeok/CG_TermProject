#include "CastleSide.h"

CastleSide::~CastleSide()
{

}

CastleSide::CastleSide()
{

}


void CastleSide::Update()
{
	glm::mat4 Rotate = glm::rotate(Unit, glm::radians(90.f), glm::vec3(0, 1, 0));
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(5,6, 0.1));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(-19,5, -39));
	Change = Trans * Rotate * Scale;
}


void CastleSide::Draw()
{

	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));


	glBindTexture(GL_TEXTURE_2D, CastleSideTexTure);
	glDrawArrays(GL_TRIANGLES, 0, 6);



}


