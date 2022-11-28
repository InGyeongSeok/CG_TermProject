#include "Cat.h"

float closelineX{};
float closelineZ{};

Cat::Cat() : 
head(Head(glm::vec3(207. / 255, 207. / 255, 207. / 255),1)),
nose(Nose(glm::vec3(36.  /255, 36.   / 255, 36.  / 255),1)), 
body(Body(glm::vec3(207. / 255, 207. / 255, 207. / 255),1)),
armL(Arm(glm::vec3(207. / 255, 207. / 255, 207. / 255), -1,1)),
armR(Arm(glm::vec3(207. / 255, 207. / 255, 207. / 255), 1,1)),
legL(Leg(glm::vec3(207. / 255, 207. / 255, 207. / 255), -1,1)),
legR(Leg(glm::vec3(207. / 255, 207. / 255, 207. / 255), 1,1)),
eyesL(Eyes(glm::vec3(255./255, 54. / 255, 54. / 255),-1,1)), 
eyesR(Eyes(glm::vec3(255. / 255, 54. / 255, 54. / 255), 1,1)), 
Position(glm::vec3(0.f, -1.f, 0.f)), Direction(0.f),
earL(Ear(glm::vec3(135. / 255, 135. / 255, 135. / 255), -1,1)),
earR(Ear(glm::vec3(135. / 255, 135. / 255, 135. / 255), 1,1)),
beardL1(Beard(glm::vec3(36. / 255, 36. / 255, 36. / 255), -1, 1,1)),
beardR1(Beard(glm::vec3(36. / 255, 36. / 255, 36. / 255), 1, 1,1)),
beardL2(Beard(glm::vec3(36. / 255, 36. / 255, 36. / 255), -1, 2,1)),
beardR2(Beard(glm::vec3(36. / 255, 36. / 255, 36. / 255), 1, 2,1)),
beardL3(Beard(glm::vec3(36. / 255, 36. / 255, 36. / 255), -1, 3,1)),
beardR3(Beard(glm::vec3(36. / 255, 36. / 255, 36. / 255), 1, 3,1)),
swordL(Sword(glm::vec3(72. / 255, 255. / 255, 255. / 255), -1,1)),
swordR(Sword(glm::vec3(72. / 255, 255. / 255, 255. / 255), 1,1))
{

}


void Cat::draw()
{
	nose.draw();
	head.draw();
	armL.draw();
	armR.draw();
	body.draw();	
	legL.draw();
	legR.draw();
	eyesL.draw();
	eyesR.draw();
	earL.draw();
	earR.draw();
	beardL1.draw();
	beardR1.draw();
	beardL2.draw();
	beardR2.draw();
	beardL3.draw();
	beardR3.draw();
	swordL.draw();
	swordR.draw();
}


void Cat::update()
{
	//직선의 방정식 구하기
	
	hero.location();
	float dz = HeroLocationZ - Position.z;
	float dx = HeroLocationX - Position.x;

	Direction = atan2(dx, dz);

	closelineX = HeroLocationX - Position.x;
	if (!(closelineX <= 0.000001 && closelineX >= -0.000001)) {

		if (closelineX >= 0) {
			closelineX -= 0.01;
			Position.x += 0.01;
		}
		if (closelineX < 0) {
			closelineX += 0.01;
			Position.x -= 0.01;
		}
	}

	closelineZ = HeroLocationZ - Position.z;
	if (!(closelineZ <= 0.000001 && closelineZ >= -0.000001)) {
		if (closelineZ > 0) {
			closelineZ -= 0.01;
			Position.z += 0.01;
		}
		if (closelineZ < 0) {
			closelineZ += 0.01;
			Position.z -= 0.01;
		}

	}

	//switch (key) {
	//case 'w':
	//case 'W':
	//	Position.z -= 0.01;
	//	//if (Position.y < -0.8f) {		//부딪치면 원복
	//	//	Position.z += 0.01;
	//	//}
	//	//if (Position.z < -1.f)
	//	//	Position.z = 1.f;
	//	Direction = 180.f;
	//	break;
	//case 'a':
	//case 'A':
	//	Position.x -= 0.01;
	//	//if (Position.y < -0.8f ) {		//부딪치면 원복
	//	//	Position.x += 0.01;
	//	//}
	//	//if (Position.x < -1.f)
	//	//	Position.x = 1.f;
	//	Direction = 270.f;
	//	break;
	//case 's':
	//case 'S':
	//	Position.z += 0.01;
	//	//if (Position.y < -0.8f) {		//부딪치면 원복
	//	//	Position.z -= 0.01;
	//	//}
	//	//if (Position.z > 1.f)
	//	//	Position.z = -1.f;
	//	Direction = 0.f;
	//	break;
	//case 'd':
	//case 'D':
	//	Position.x += 0.01;
	//	//if (Position.y < -0.8f ) {		//부딪치면 원복
	//	//	Position.x -= 0.01;
	//	//}
	//	//if (Position.x > 1.f)
	//	//	Position.x = -1.f;
	//	Direction = 90.f;
	//	break;
	//
	//case 'i':
	//case 'I':
	//	Position = glm::vec3(0.f, -1.f, 0.f);
	//	Direction = 0.f;
	//	carAddX = 0.f;
	//	carAddZ = 0.f;
	//	carY = 0.f;
	//	break;
	//}


	nose.keyIn(Position, Direction);
	head.keyIn(Position, Direction);
	armL.keyIn(Position, Direction);
	armR.keyIn(Position, Direction);
	body.keyIn(Position, Direction);
	legL.keyIn(Position, Direction);
	legR.keyIn(Position, Direction);
	eyesL.keyIn(Position, Direction);
	eyesR.keyIn(Position, Direction);
	earL.keyIn(Position, Direction);
	earR.keyIn(Position, Direction);
	beardL1.keyIn(Position, Direction);
	beardR1.keyIn(Position, Direction);
	beardL2.keyIn(Position, Direction);
	beardR2.keyIn(Position, Direction);
	beardL3.keyIn(Position, Direction);
	beardR3.keyIn(Position, Direction);
	swordL.keyIn(Position, Direction);
	swordR.keyIn(Position, Direction);
}

Cat::~Cat()
{
}

float Cat::getLeft()
{
	return Position.x - 0.15f;
}

float Cat::getRight()
{
	return Position.x + 0.15f;
}

float Cat::getBehind()
{
	return Position.z - 0.15f;
}

float Cat::getFront()
{
	return Position.z + 0.15f;
}

float Cat::getBottom()
{
	return Position.y;
}

float Cat::getTop()
{
	return 0.0f;				//계산하기 귀찮으니 대충 0으로 잡겠음(의미없는값)
}


