#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Elephant :
	public DisplayableObject, public Animation
{
public:
	Elephant() { elephantTex = Scene::GetTexture("./Textures/elephant.bmp"); };
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

	GLuint elephantTex;

	float earAngle = 0;
	bool reverseEarFlap = false;
};