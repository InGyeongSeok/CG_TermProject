#include "Motion.h"
//VAngleY
//VAngleX
GLvoid passiveMotion(int x, int y) {


	VAngleY += (x - width / 2) / 12.5;

	if (glm::radians(VAngleX) < -0.3) {
		VAngleX += 0.05;
	}
	if (glm::radians(VAngleX) > 0.3) {
		VAngleX -= 0.05;
	}
	if (glm::radians(VAngleX) <= 0.3f && glm::radians(VAngleX) >= -0.3f) {
		VAngleX += (y - height / 2) / 12.5;
	}

	glutWarpPointer(width / 2, height / 2);
	//glutPostRedisplay();
}