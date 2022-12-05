#include "Tree.h"


Tree::~Tree()
{
}

Tree::Tree(float xpos, float ypos, float zpos)
{

	Ypos = ypos;
	Zpos = zpos;
	Xpos = xpos;

}


void Tree::Update()
{

	glm::mat4 Scale = glm::scale(Unit, glm::vec3(1, 2,0.1));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos, Ypos, Zpos));

	Change = Trans * Scale;
}


void Tree::Draw()
{
	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));

	
		glBindTexture(GL_TEXTURE_2D, TreeTexture);
		glDrawArrays(GL_TRIANGLES, 0, 6);


}


