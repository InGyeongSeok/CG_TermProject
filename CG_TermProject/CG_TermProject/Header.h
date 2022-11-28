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
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>

using namespace std;

extern GLint width, height;

extern GLuint aColor;

extern GLuint shaderID; //--- 세이더 프로그램 이름
extern GLuint VAO;
extern GLuint sphereVAO;
extern GLuint pyramidVAO;

extern float Rot;
extern vector<glm::vec3> vertex1; //육면체
extern vector<glm::vec3> vertex2; //구
extern vector<glm::vec3> vertex3; //피라미드

extern float lightRot;


extern float lightPosX;
extern float lightPosY;
extern float lightPosZ;


extern float Addx;


extern float carY;


extern float carAddX;
extern float carAddY;
extern float carAddZ;



extern bool isW, isA, isS, isD;

extern float VAngleX;
extern float VAngleY;
extern float HeroMovX;
extern float HeroMovY;
extern float HeroMovZ;
//156. / 255, 91. / 255, 54. / 255 곰 색깔!?



extern float HeroLocationX;
extern float HeroLocationZ;