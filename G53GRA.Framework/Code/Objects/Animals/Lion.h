#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

#define MOONWALK_RANGE 20

class Lion:
	public DisplayableObject,
	public Animation
{
public:
	Lion() {};
	~Lion() {};

	void Display();
	void Update(const double& dT);
private:
	void drawHead();
	void drawBody();
	void drawLeg();
	void drawTail();
	void drawEar();
	void drawEye();
	void drawMouth();

	float legAngle = 0, wiggle = 0;
	bool reverseLeg = false, reverseMoonWalk = false, enableSpin = false, reverseWiggle = false;
	float moonwalkX = MOONWALK_RANGE, moonwalkRotation = 0;

	GLuint lionTex = Scene::GetTexture("./Textures/lion.bmp");
};