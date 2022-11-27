#include "Arm.h"

Arm::Arm()
{
}

Arm::Arm(glm::vec3 Color, int i, int monster) : i(i), rotate(0.f), isrotDirec(false), monster(monster)
{
	this->Color = Color;
	update();
}


Arm::~Arm()
{
}

void Arm::update()
{
	if (monster == 3) {
		if (isrotDirec) {
			rotate += 2.5f;
			if (rotate > 30.f)
				isrotDirec = false;
		}
		else {
			rotate -= 2.5f;
			if (rotate < -30.f)
				isrotDirec = true;
		}

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.01, 0.03, 0.01));

		Change = Scale * Trans;		// 위로 올리고 축소

		Trans = glm::translate(Unit, glm::vec3(0, -0.15, 0));
		Change = Trans * Change;	//팔 벌려주기위해 원점에 맞춰주고

		Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, i * 1.f));
		Change = Rotate * Change;	//벌려준다.

		Rotate = glm::rotate(Unit, glm::radians(rotate), glm::vec3(i * 1.f, 0, 0));
		Change = Rotate * Change;	//팔 흔드는 모션도 해줌

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//다시 원위치 시켜주고

		Trans = glm::translate(Unit, glm::vec3(0, 0.25, 0));
		Change = Trans * Change;	// 원하는 높이

		Trans = glm::translate(Unit, glm::vec3(i * 0.13, 0, 0));
		Change = Trans * Change;	// 내가 원하는 위치(왼쪽 오른쪽)

		Rotate = glm::rotate(Unit, glm::radians(Direction), glm::vec3(0, 1, 0));
		Change = Rotate * Change;	//캐릭터 돌려주기

		Trans = glm::translate(Unit, Position);		// 내 이동위치로 무브
		Change = Trans * Change;
	}
	else {
		if (isrotDirec) {
			rotate += 2.5f;
			if (rotate > 30.f)
				isrotDirec = false;
		}
		else {
			rotate -= 2.5f;
			if (rotate < -30.f)
				isrotDirec = true;
		}

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.03, 0.075, 0.03));

		Change = Scale * Trans;		// 위로 올리고 축소

		Trans = glm::translate(Unit, glm::vec3(0, -0.15, 0));
		Change = Trans * Change;	//팔 벌려주기위해 원점에 맞춰주고

		Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, i * 1.f));
		Change = Rotate * Change;	//벌려준다.

		Rotate = glm::rotate(Unit, glm::radians(rotate), glm::vec3(i * 1.f, 0, 0));
		Change = Rotate * Change;	//팔 흔드는 모션도 해줌

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//다시 원위치 시켜주고

		Trans = glm::translate(Unit, glm::vec3(0, 0.25, 0));
		Change = Trans * Change;	// 원하는 높이

		Trans = glm::translate(Unit, glm::vec3(i * 0.13, 0, 0));
		Change = Trans * Change;	// 내가 원하는 위치(왼쪽 오른쪽)

		Rotate = glm::rotate(Unit, glm::radians(Direction), glm::vec3(0, 1, 0));
		Change = Rotate * Change;	//캐릭터 돌려주기

		Trans = glm::translate(Unit, Position);		// 내 이동위치로 무브
		Change = Trans * Change;
	}
}


void Arm::BindVAO()
{
	if (monster == 3) {
		glBindVertexArray(sphereVAO);
	}
	else
		glBindVertexArray(VAO);
}

void Arm::DrawArrays()
{
	if (monster == 3) {
		glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
	}
	else
		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
	

}