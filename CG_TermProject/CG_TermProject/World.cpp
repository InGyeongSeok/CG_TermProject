#include "World.h"


World::~World()
{
}

World::World(float xpos, float ypos, float zpos)
{

	Ypos = ypos;
	Zpos = zpos;
	Xpos = xpos;

}


void World::Update()
{

	glm::mat4 Scale = glm::scale(Unit, glm::vec3(40, 50,40));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos, Ypos, Zpos));

	Change = Trans * Scale;
}


void World::Draw()
{
	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));

	for (int i = 0; i < 6; ++i) {
		glBindTexture(GL_TEXTURE_2D, Texture[i]);
		glDrawArrays(GL_TRIANGLES, i * 6, 6);
	}

}


