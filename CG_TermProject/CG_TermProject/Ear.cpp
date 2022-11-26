#include "Ear.h"

Ear::Ear()
{
}

Ear::Ear(glm::vec3 Color, int i) :i{ i }
{
	this->Color = Color;
	update();
}

Ear::~Ear()
{
}

void Ear::update()
{
	Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
	Scale = glm::scale(Unit, glm::vec3(0.037, 0.037, 0.037));	//위에서 봤기때문에 납작해보여서 y 늘려줌
	Change = Scale;		//위로 올리고 축소

	Trans = glm::translate(Unit, glm::vec3(0, 0.64, 0));
	Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.0));
	Change = Trans * Change;	//원하는 위치로 이동

	Trans = glm::translate(Unit, glm::vec3(i * 0.043, 0, 0));
	Change = Trans * Change;	// 내가 원하는 위치(왼쪽 오른쪽)

	Rotate = glm::rotate(Unit, glm::radians(Direction), glm::vec3(0, 1, 0));
	Change = Rotate * Change;	//캐릭터 돌려주기

	Trans = glm::translate(Unit, Position);
	Change = Trans * Change;	// 내 포지션으로 이동
}


void Ear::BindVAO()
{
	glBindVertexArray(pyramidVAO);
}

void Ear::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, vertex3.size() * 3);

}