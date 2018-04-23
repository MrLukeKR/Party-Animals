#include "DisplayableObject.h"
#include "Animation.h"

#define TOTAL_COLOURS 256 * 256 * 256
#pragma once

class Screen :
	public DisplayableObject,
	public Animation
{
public:
	Screen(bool invert);
	~Screen() {};

	void Display();
	void Update(const double& dT);
private:
	double x, y, a, b, c;
	float attractorRotation = 90.f;
	float red = 0, green = 0, blue = 0;
	unsigned int col = TOTAL_COLOURS;
	bool invert, reverseA, reverseB, reverseC;
};