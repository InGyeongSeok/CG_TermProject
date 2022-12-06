#include "Timer.h"

void timer(int value) {

	if (isW) {
		carAddZ -= 0.075 * glm::cos(glm::radians(VAngleY));
		carAddX += 0.075 * glm::sin(glm::radians(VAngleY));

		HeroMovZ -= 0.075 * glm::cos(glm::radians(VAngleY));
		HeroMovX += 0.075 * glm::sin(glm::radians(VAngleY));

	}
	else if (isA) {
		carAddZ -= 0.075 * glm::sin(glm::radians(VAngleY));
		carAddX -= 0.075 * glm::cos(glm::radians(VAngleY));

		HeroMovZ -= 0.075 * glm::sin(glm::radians(VAngleY));
		HeroMovX -= 0.075 * glm::cos(glm::radians(VAngleY));
	}
	else if (isS) {
		carAddZ += 0.075 * glm::cos(glm::radians(VAngleY));
		carAddX -= 0.075 * glm::sin(glm::radians(VAngleY));

		HeroMovZ += 0.075 * glm::cos(glm::radians(VAngleY));
		HeroMovX -= 0.075 * glm::sin(glm::radians(VAngleY));
	}
	else if (isD) {
		carAddZ += 0.075 * glm::sin(glm::radians(VAngleY));
		carAddX += 0.075 * glm::cos(glm::radians(VAngleY));

		HeroMovZ += 0.075 * glm::sin(glm::radians(VAngleY));
		HeroMovX += 0.075 * glm::cos(glm::radians(VAngleY));
	}
	if (isJump) {
		hero.Jump();

	}

	for (int i = 0; i < cats.size(); ++i) {
		cats[i]->update();
	}
	for (int i = 0; i < dogs.size(); ++i) {
		dogs[i]->update();
	}

	if (BearLife) {
		bear.update();
	}
	world.Update();
	glutPostRedisplay();
	glutTimerFunc(14, timer, 1);
}