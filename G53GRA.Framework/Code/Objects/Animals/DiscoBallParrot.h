#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class DiscoBallParrot :
	public DisplayableObject, public Animation
{
public:
	DiscoBallParrot();
	~DiscoBallParrot() {};

	void Display();
	void Update(const double& dT);

private:
	void drawDiscoBall();
	void drawParrot();
	void drawRays();
	void drawTailFeathers();
	void drawFeather();
	void drawBody();
	void drawWing(bool invert);
	void drawHead();
	void drawBeak();
	void drawFeet();
	void drawString();

	GLuint discoBallTex;
	bool reverseAltitude = false, reverseFlap = false;

	float *degree, *x, *y, *z;

	float currentAnimationTime = 0, discoBallRotation = 0, altitudeChange = 0, wingAngle = 0;
};