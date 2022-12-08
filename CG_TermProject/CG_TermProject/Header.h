#pragma once

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "freeglut.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <gl/glew.h>                     
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>

using namespace std;

extern GLint width, height;

extern GLuint aColor;

extern GLuint shaderID; //--- ���̴� ���α׷� �̸�
extern GLuint VAO;
extern GLuint sphereVAO;
extern GLuint pyramidVAO;
extern GLuint crossVAO;
extern GLuint GrassVAO;
extern GLuint castleVAO;
extern GLuint TreeTexture[3];
extern GLuint GrassTexture[3];
extern GLuint RoomTexture[3];
extern GLuint HeroHPVAO;
extern float Rot;
extern vector<glm::vec3> vertex1; //����ü
extern vector<glm::vec3> vertex2; //��
extern vector<glm::vec3> vertex3; //�Ƕ�̵�
extern vector<glm::vec3> vertex4;
extern vector<glm::vec3> vertex5;
extern float lightRot;

extern float lightPosX;
extern float lightPosY;
extern float lightPosZ;
extern float lightColorR;
extern float lightColorG;
extern float lightColorB;

extern float Addx;
extern float carY;

extern float carAddX;
extern float carAddY;
extern float carAddZ;
extern glm::vec3 TermGunDir;
extern glm::vec3 cameraPos;

extern int BulletLimit;

extern bool isW, isA, isS, isD;
extern bool isJump;
extern bool jumpUp;

extern float cameraJump;

extern float VAngleX;
extern float VAngleY;
extern float HeroMovY;
//156. / 255, 91. / 255, 54. / 255 �� ����!?
extern bool catlive;
extern bool doglive;
extern bool bearlive;


extern float HeroLocationX;
extern float HeroLocationZ;

extern void AnimalCollideCat();
extern void AnimalCollideDog();

extern void BulletCollideCat();
extern void BulletCollideDog();
extern void BulletCollideBear();
extern void Catroomtest();
extern void Dogroomtest();
extern void Bearroomtest();
extern void HeroVSDog();
extern void HeroVSBear();
extern void HeroVSCat();

extern bool commandGun;
extern bool BearLife;

extern glm::vec3 GunDir;
extern bool isParticle;
extern bool isBullet;
extern const glm::mat4 Unit;
extern GLuint CastleTexture;
extern GLuint CastleSideTexTure;
extern GLuint Texture[6];
extern float CatEndPosX;
extern float CatEndPosZ;

extern bool catopen;
extern bool dogopen;
extern float openingCat;
extern float openingDog;
extern int catdead;
extern int dogdead;