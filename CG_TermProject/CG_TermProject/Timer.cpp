#include "Timer.h"

void timer(int value) {

	/*if (isW) {
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
	}*/

	//if (isW) {
	//	dog.update('w');
	//}
	//if (isA) {
	//	dog.update('a');
	//}
	//if (isS) {
	//	dog.update('s');
	//}
	//if (isD) {
	//	dog.update('d');
	//}
	//

	//if (isW) {
	//	bear.update('w');
	//}
	//if (isA) {
	//	bear.update('a');
	//}
	//if (isS) {
	//	bear.update('s');
	//}
	//if (isD) {
	//	bear.update('d');
	//}

	cat.update();
	dog.update();
	bear.update();

	glutPostRedisplay();
	glutTimerFunc(14, timer, 1);
}