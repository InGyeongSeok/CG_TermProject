#include "Mouse.h"

int BulletLimit;
GLvoid Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		isBullet = true;
		PlaySound(L"�����ѼҸ�.wav", 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

		//PlaySound(NULL, NULL, 0);
		BulletLimit = 0;
		isBullet = false;
	}
}