#include "Motion.h"

GLvoid passiveMotion(int x, int y) {


	VAngleY += (x - width / 2) / 12.5;


	VAngleX += (y - height / 2) / 12.5;
	if (VAngleX >= 15.f) {
		VAngleX = 15.f;
	}
	else if (VAngleX <= -15.f) {
		VAngleX = -15.f;
	}

	glutWarpPointer(width / 2, height / 2);
	//glutPostRedisplay();
}