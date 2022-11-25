#include "Timer.h"
void timer(int value) {

	CubeBottom.Update();
	CubeMid.Update();
	lightsphere.Update();
	CubeTopL.Update();
	CubeTopR.Update();
	

	if (ybutton) {
		Rot += 0.5f;
	}
	if (rbutton) {
		lightRot += 0.5 * rbutton;
	}

	if (abutton) {
		carY += 0.3f;
	}

	glutPostRedisplay();
	glutTimerFunc(14, timer, 1);
}