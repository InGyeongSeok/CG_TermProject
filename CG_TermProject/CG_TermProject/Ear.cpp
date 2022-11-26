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
	Scale = glm::scale(Unit, glm::vec3(0.037, 0.037, 0.037));	//������ �ñ⶧���� �����غ����� y �÷���
	Change = Scale;		//���� �ø��� ���

	Trans = glm::translate(Unit, glm::vec3(0, 0.64, 0));
	Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.0));
	Change = Trans * Change;	//���ϴ� ��ġ�� �̵�

	Trans = glm::translate(Unit, glm::vec3(i * 0.043, 0, 0));
	Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

	Rotate = glm::rotate(Unit, glm::radians(Direction), glm::vec3(0, 1, 0));
	Change = Rotate * Change;	//ĳ���� �����ֱ�

	Trans = glm::translate(Unit, Position);
	Change = Trans * Change;	// �� ���������� �̵�
}


void Ear::BindVAO()
{
	glBindVertexArray(pyramidVAO);
}

void Ear::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, vertex3.size() * 3);

}