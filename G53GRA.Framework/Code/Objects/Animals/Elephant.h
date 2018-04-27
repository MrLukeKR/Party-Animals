#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

/* Party Animals: Disco Ball Parrot (Header File)
   Author: Luke K. Rose
   April 2018
*/

class Elephant :
	public DisplayableObject, public Animation
{
public:
	Elephant() {};
	~Elephant() {};

	void Display();
	void Update(const double& dT);

private:
	void drawBody();
	void drawLeg();
	void drawTrunk();
	void drawEyes();
	void drawEars();
	void drawHead();
	void drawTusks();

	GLuint elephantTex = Scene::GetTexture("./Textures/elephant.bmp");;

	float animationAngle = 0;
	bool reverseAnimation = false;
};