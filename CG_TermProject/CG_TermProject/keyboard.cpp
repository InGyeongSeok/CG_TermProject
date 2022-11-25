#include "keyboard.h"
bool nbutton = true;
bool mbutton = false;
bool ybutton = false;
int rbutton = 0;
bool qbutton = false;
bool abutton = false;

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case'c':
	case'C':
		if (4 == lightcolorN) {
			lightcolorN = 0;
		}
		if (2 == lightcolorN) {
			lightColorR = 1.;
			lightColorG = 1.;
			lightColorB = 1.;
		}
		if (0 == lightcolorN) {
			lightColorR = 255. / 255.;
			lightColorG = 113. / 255.;
			lightColorB = 113. / 255.;
		}
		if (1 == lightcolorN) {
			lightColorR = 103. / 255.;
			lightColorG = 153. / 255.;
			lightColorB = 255. / 255.;
		}
		lightcolorN += 1;
		break;
	case'r':
		rbutton != 1 ? rbutton = 1 : rbutton = 0;
		break;
	case'R':
		rbutton != -1 ? rbutton = -1 : rbutton = 0;
		break;
	case's':
		rbutton = false;
		abutton = false;
		break;
	case'z':
		carAddZ += 0.3f;

		break;
	case'Z':
		carAddZ -= 0.3f;

		break;
	case'X':
		carAddX -= 0.3f;
		break;
	case'x':
		carAddX += 0.3f;
		break;
	case'a':
		abutton = true;
		break;
	case'm':
		mbutton = not mbutton;
		if (mbutton == true) {
			GLuint LightOff =  glGetUniformLocation(shaderID, "LightOff");
			glUniform1i(LightOff, 1);
		}
		else {
			GLuint LightOff = glGetUniformLocation(shaderID, "LightOff");
			glUniform1i(LightOff, 0);
		}
		break;

	}
		glutPostRedisplay(); //--- 배경색이 바뀔 때마다 출력 콜백 함수를 호출하여 화면을 refresh 한다
}


GLvoid SpecialKeyboardUP(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		break;

	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	}
}