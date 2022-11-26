#include "Timer.h"
void timer(int value) {

	if (isW) {
		cat.update('w');
	}
	if (isA) {
		cat.update('a');
	}
	if (isS) {
		cat.update('s');
	}
	if (isD) {
		cat.update('d');
	}


	glutPostRedisplay();
	glutTimerFunc(14, timer, 1);
}