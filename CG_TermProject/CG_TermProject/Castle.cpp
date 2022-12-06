#include "Castle.h"





Castle::~Castle()
{

}

Castle::Castle()
{
	
}


void Castle::Update()
{
	
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(20 ,20, 0.1));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(0, 15,-34));
	Change = Trans * Scale;
}


void Castle::Draw()
{
	
	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));


	glBindTexture(GL_TEXTURE_2D, CastleTexture);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	


}


