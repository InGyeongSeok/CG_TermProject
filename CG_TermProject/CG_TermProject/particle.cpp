#include "particle.h"
float drop{};


Particle::Particle(float XPos, float YPos, float ZPos) : Xpos{ XPos }, Ypos{0}, Zpos{ZPos}
{ 

	random_device rd;
	default_random_engine dre(rd());
	uniform_real_distribution<float> urd{ 0, 255 };
	uniform_real_distribution<float> urdX(-0.5f, 0.5f);
	uniform_real_distribution<float> urdY(-0.5f, 0.5f);
	uniform_real_distribution<float> urdZ(-0.5f, 0.5f);
	uniform_real_distribution<float> urdsize(0.005f,0.01f);
	uniform_int_distribution<int> updown(0, 1);
	color = glm::vec3(urd(dre) / 255., urd(dre) / 255., urd(dre) / 255.);
	
	dirX = urdX(dre);
	dirY = urdY(dre);
	dirZ = urdZ(dre);
	size = urdsize(dre);

	
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
	
		glm::mat4 Scale = glm::scale(Unit, glm::vec3(size, size, size));
		glm::mat4 Trans = glm::translate(Unit, glm::vec3(Xpos + dirX + ParticleX, Ypos + dirY+drop, Zpos + dirZ + ParticleZ));
		Change = Trans * Scale;
		
		drop -= 0.0001;
		
}

