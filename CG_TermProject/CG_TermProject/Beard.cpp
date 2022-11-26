#include "Beard.h"

Beard::Beard()
{
}

Beard::Beard(glm::vec3 Color, int i,int pos) :i{ i },pos{pos}
{
	this->Color = Color;
	update();
}

Beard::~Beard()
{
}

void Beard::update()
{
	Scale = glm::scale(Unit, glm::vec3(0.033, 0.0025, 0.002));	//위에서 봤기때문에 납작해보여서 y 늘려줌
	Change = Scale;		

	if (pos == 1) {
		Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, 1));
		Change = Rotate * Change;
	}
	else if(pos == 2) {
		Rotate = glm::rotate(Unit, glm::radians(0.f), glm::vec3(0, 0, 1));
		Change = Rotate * Change;
	}
	else if(pos == 3) {
		Rotate = glm::rotate(Unit, glm::radians(-30.f), glm::vec3(0, 0, 1));
		Change = Rotate * Change;
	}

	if (i == -1) {
		Rotate = glm::rotate(Unit, glm::radians(180.f), glm::vec3(0, 1, 0));
		Change = Rotate * Change;
	}

	if (pos == 1) {
		Trans = glm::translate(Unit, glm::vec3(0, 0.535, 0));
		Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
		Change = Trans * Change;	//원하는 위치로 이동
	}
	else if (pos == 2) {
	Trans = glm::translate(Unit, glm::vec3(0, 0.51, 0));
	Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
	Change = Trans * Change;	//원하는 위치로 이동
	}
	else if (pos == 3) {
		Trans = glm::translate(Unit, glm::vec3(0, 0.485, 0));
		Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
		Change = Trans * Change;	//원하는 위치로 이동
	}

	Trans = glm::translate(Unit, glm::vec3(i * 0.07, 0, 0));
	Change = Trans * Change;	// 내가 원하는 위치(왼쪽 오른쪽)


	Rotate = glm::rotate(Unit, glm::radians(Direction), glm::vec3(0, 1, 0));
	Change = Rotate * Change;	//캐릭터 돌려주기

	Trans = glm::translate(Unit, Position);
	Change = Trans * Change;	// 내 포지션으로 이동
}


void Beard::BindVAO()
{
	glBindVertexArray(VAO);
}

void Beard::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);

}