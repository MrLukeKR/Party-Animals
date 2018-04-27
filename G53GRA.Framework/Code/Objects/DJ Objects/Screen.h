#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

#define TOTAL_COLOURS 256 * 256 * 256


/*
Party Animals: Screen (Header File)
Author: Luke K. Rose
April 2018
*/

class Screen :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Screen(bool invert);
	~Screen() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private variables
	*/
	float x, y, a, b;
	float red = 0, green = 0, blue = 0;
	unsigned int col = TOTAL_COLOURS;
	bool invert, reverseA, reverseB;
};