#include "particle.h"
int i = 0;

Particle::Particle(float XPos, float YPos, float ZPos) : Xpos{ XPos }, Ypos{YPos}, Zpos{ZPos}
{ 

	random_device rd;
	default_random_engine dre(rd());
	uniform_real_distribution<float> urd{ 0, 255 };
	uniform_real_distribution<float> urdX(-1.0f, 1.0f);
	uniform_real_distribution<float> urdY(-1.0f, 1.0f);
	uniform_real_distribution<float> urdZ(-1.0f, 1.0f);
	color = glm::vec3(urd(dre) / 255., urd(dre) / 255., urd(dre) / 255.);
	for (int i = 0; i < 10; i++) {
		dirX[i] = urdX(dre);
		dirY[i] = urdY(dre);
		dirZ[i] = urdZ(dre);
	}
}

Particle::~Particle() {

}

void Particle::draw()
{


	glBindVertexArray(VAO);
	GLuint SelectColor = glGetUniformLocation(shaderID, "SelectColor");
	glUniform1i(SelectColor, 1);

	GLuint aColor = glGetUniformLocation(shaderID, "objectColor");
	glUniform3f(aColor, color.r, color.g, color.b);
	GLuint modelLocation = glGetUniformLocation(shaderID, "modelTransform");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Change));
	glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);

}

void Particle::update() 
{	
	glm::mat4 Scale = glm::scale(Unit, glm::vec3(0.1 - i * 0.01, 0.1 - i * 0.01, 0.1 - i * 0.01));
	glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos + dirX[i], Ypos + dirY[i], Zpos + dirZ[i]));
	//glm::mat4 AddTrans = glm::translate(Unit, glm::vec3(0., 1, 0.));
	Change = Trans * Scale;
	++i;
}

