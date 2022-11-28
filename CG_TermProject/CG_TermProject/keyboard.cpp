#include "keyboard.h"
bool isW, isA, isS, isD;


GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
	case 'W':
		HeroMovZ -= 0.1;
		isW = true;
		break;
	case 'a':
	case 'A':
		HeroMovX -= 0.1;

		isA = true;
		break;
	case 's':
	case 'S':
		HeroMovZ += 0.1f;
		isS = true;
		break;
	case 'd':
	case 'D':
		HeroMovX += 0.1;
		isD = true;
		break;

	case'z':
		carAddZ -= 1;
		break;
	case'Z':
		carAddZ += 1;
		break;
	case 'q':
	case 'Q':
		glutLeaveMainLoop();
		break;
	}
	glutPostRedisplay(); //--- 배경색이 바뀔 때마다 출력 콜백 함수를 호출하여 화면을 refresh 한다
}


GLvoid SpecialKeyboard(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		isA = true;
		break;
	case GLUT_KEY_RIGHT:
		isD = true;
		break;
	case GLUT_KEY_UP:
		isW = true;
		break;
	case GLUT_KEY_DOWN:
		isS = true;
		break;
	}

	glutPostRedisplay();
}