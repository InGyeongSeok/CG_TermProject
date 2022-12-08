#include "Timer.h"

void timer(int value) {

	if (isW) {
		carAddZ -= 0.075 * glm::cos(glm::radians(VAngleY));
		carAddX += 0.075 * glm::sin(glm::radians(VAngleY));

	
		hero.isW();
	}
	else if (isA) {
		carAddZ -= 0.075 * glm::sin(glm::radians(VAngleY));
		carAddX -= 0.075 * glm::cos(glm::radians(VAngleY));
		hero.isA();
	}
	else if (isS) {
		carAddZ += 0.075 * glm::cos(glm::radians(VAngleY));
		carAddX -= 0.075 * glm::sin(glm::radians(VAngleY));
		hero.isS();
	
	}
	else if (isD) {
		carAddZ += 0.075 * glm::sin(glm::radians(VAngleY));
		carAddX += 0.075 * glm::cos(glm::radians(VAngleY));
		hero.isD();
		
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

	if (catopen && !(openingCat >= 1)) {
		openingCat += 0.01;
	}

	if (dogopen && !(openingDog >= 1)) {
		openingDog += 0.01;
	}
	world.Update();
	glutPostRedisplay();
	glutTimerFunc(14, timer, 1);
}