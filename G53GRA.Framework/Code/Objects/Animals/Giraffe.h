#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Giraffe :
	public DisplayableObject, 
	public Animation
{
public:
	Giraffe();
	~Giraffe();

	void Display();
	void Update(const double& dT);

private:
	float animationTime = 1;
	float currentAnimationTime = 0;
	float neckAngle, headAngle, neckSpinAngle;
	float neckHeight = 2.f;
	float headHeight = 0.25f;
	void drawGiraffe();
	void drawBody();
	void drawLeg();
	void drawNeck();
	void drawHead();
	void drawTail();
	void box(float sx, float sy, float sz, GLuint texID);

	GLuint giraffeTex;
};

