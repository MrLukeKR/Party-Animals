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
	float elbowRotation = 0, shoulderRotation = -80;
	float currentAnimationTime = 0;
	float animationTime = .5f;
};