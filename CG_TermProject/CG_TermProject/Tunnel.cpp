#include "Tunnel.h"

bool Dogopen = false;
bool Bearopen = false;

Tunnel::~Tunnel()
{
}

Tunnel::Tunnel(double xPos, double zPos)
{
	Xpos = xPos;
	Zpos = zPos;

}


void Tunnel::Update()
{
	//FixUpdate();
	//Tx = glm::translate(Tx, glm::vec3(0, 0, 0));
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(1, 1, 1));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos, 0, Zpos));
	//glm::mat4 Trans1 = glm::translate(Unit, glm::vec3(0, 1, 0));
	Change = Trans* Scale;
}

void Tunnel::Draw()
{
		glBindVertexArray(VAO);
		GLuint Color = glGetUniformLocation(shaderID, "objectColor");
		glUniform4f(Color, 0,0,0, 1.0);

		GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change)); //--- modelTransform 변수에 변환

		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);



}


