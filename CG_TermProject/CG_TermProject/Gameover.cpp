#include "Gameover.h"


Gameover::~Gameover()
{

}

Gameover::Gameover(float Xpos, float Zpos) : Xpos{Xpos}, Zpos{Zpos}
{
	
}


void Gameover::Update()
{
	float dz = HeroLocationZ - Xpos;
	float dx = HeroLocationX - Zpos;
	Direction = atan2(dx, dz);

	glm::mat4 Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(3.0, 3, 0.1));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos, 1, Zpos));

	Change = Trans * Rotate * Scale;
}


void Gameover::Draw()
{
	
	glBindVertexArray(VAO);
	GLuint selectColorLocation = glGetUniformLocation(shaderID, "selectColor");	//--- 텍스처 사용
	glUniform1i(selectColorLocation, 1);

	GLuint model = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(Change));


	glBindTexture(GL_TEXTURE_2D, GameoverTexture);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	

}


