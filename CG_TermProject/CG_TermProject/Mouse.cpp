#include "Mouse.h"

bool commandGun = false;

GLvoid Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		commandGun = true;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		commandGun = false;
	}
}