#include "Mouse.h"

int BulletLimit;
GLvoid Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (!herodead) {
			isBullet = true;
		}
		PlaySound(L"�����ѼҸ�.wav", 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		BulletLimit = 0;
		isBullet = false;
	}
}