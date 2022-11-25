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
extern GLuint XYZVAO;
extern GLuint sphereVAO;

extern bool nbutton;
extern float Rot;
extern vector<glm::vec3> vertex1;
extern vector<glm::vec3> vertex2;

extern float lightRot;
extern bool mbutton;
extern bool ybutton;
extern int rbutton;
extern bool qbutton;
extern bool abutton;


extern float lightPosX;
extern float lightPosY;
extern float lightPosZ;


extern GLuint CircleVAO;
extern float Addx;
extern int lightcolorN;
extern float lightColorR;
extern float lightColorG;
extern float lightColorB;

extern float carY;


extern float carAddX;
extern float carAddY;
extern float carAddZ;