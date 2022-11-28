#include "Mouse.h"

float MouseX{};
float MouseY{};

GLvoid Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Gun gun{ float(x),0,float(y) };
		gun.Update();
		gun.Draw();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
	}
}