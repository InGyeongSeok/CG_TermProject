#include "keyboard.h"
bool isW, isA, isS, isD;
bool isJump;

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
	case 'W':
		isW = true;
		break;

	case 'a':
	case 'A':
		isA = true;
		break;
	case 's':
	case 'S':
		isS = true;
		break;
	case 'd':
	case 'D':
		isD = true;
		break;
	case' ':
		isJump = true;
		jumpUp = true;
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
	glutPostRedisplay(); 
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
	case GLUT_KEY_F5: 
		glutFullScreenToggle();
		break;
	}

	glutPostRedisplay();
}