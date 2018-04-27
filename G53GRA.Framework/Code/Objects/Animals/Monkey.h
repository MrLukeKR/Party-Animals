#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Monkey :
	public DisplayableObject,
	public Animation 
{
public:
	Monkey() {};
	~Monkey() {};

	void Display();
	void Update(const double& dT);
private:
	void drawBody();
	void drawLeftArm();
	void drawRightArm();
	void drawHead();
	void drawEye();
	void drawEar();
	void drawSunglasses();
	void drawMouth();
	void drawTail();
	void drawStool();

	bool reverseShift = false;
	float elbowRotation = 0, shoulderRotation = -80, headShift = 0;
	float currentAnimationTime = 0;
	float animationTime = .5f;
};