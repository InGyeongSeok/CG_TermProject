#include "Tree.h"


Tree::~Tree()
{
}

Tree::Tree()
{
	random_device rd;
	default_random_engine dre(rd());
	uniform_real_distribution<float> XZ{ -30.f,30.f };
	
	uniform_int_distribution<int> tree{ 0,2 };
	Xpos = XZ(dre);
	Zpos = XZ(dre);
	Treenum = tree(dre);
}


void Tree::Update()
{

	glm::mat4 Scale = glm::scale(Unit, glm::vec3(1.5, 2,0.1));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos, 1, Zpos));

	Change = Trans * Scale;
}


void Tree::Draw()
{
	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));


	glBindTexture(GL_TEXTURE_2D, TreeTexture[Treenum]);
	glDrawArrays(GL_TRIANGLES, 0, 6);


}


