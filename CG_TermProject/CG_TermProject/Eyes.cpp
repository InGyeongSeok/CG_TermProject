#include "Eyes.h"

Eyes::Eyes()
{
}

Eyes::Eyes(glm::vec3 Color,int i):i{i}
{
	this->Color = Color;
	update();
}

Eyes::~Eyes()
{
}

void Eyes::update()
{
	Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
	Scale = glm::scale(Unit, glm::vec3(0.0033, 0.0033, 0.0033));	//������ �ñ⶧���� �����غ����� y �÷���
	Change = Scale ;		//���� �ø��� ���

	Trans = glm::translate(Unit, glm::vec3(0, 0.57, 0));
	Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.075));
	Change = Trans * Change;	//���ϴ� ��ġ�� �̵�

	Trans = glm::translate(Unit, glm::vec3(i * 0.043, 0, 0));
	Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

	Rotate = glm::rotate(Unit, glm::radians(Direction), glm::vec3(0, 1, 0));
	Change = Rotate * Change;	//ĳ���� �����ֱ�

	Trans = glm::translate(Unit, Position);
	Change = Trans * Change;	// �� ���������� �̵�
}


void Eyes::BindVAO()
{
	glBindVertexArray(sphereVAO);
}

void Eyes::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);

}