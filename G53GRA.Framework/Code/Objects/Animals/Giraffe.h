#pragma once
#include "DisplayableObject.h"
class Giraffe :
	public DisplayableObject
{
public:
	Giraffe();
	~Giraffe();

	void Display();

private:
	float neckAngle = 10.f, headAngle = -90.f;
	float neckHeight = 3.5f;
	float headHeight = 0.5f;
	void drawBody();
	void drawLeg();
	void drawNeck();
	void drawHead();
	void box(float sx, float sy, float sz);
};

