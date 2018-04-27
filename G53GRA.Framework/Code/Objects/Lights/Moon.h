#pragma once

#define _USE_MATH_DEFINES

#include ".\DisplayableObject.h"
#include ".\Animation.h"
#include <cmath>

/*
Party Animals: Moon (Header File)
Author: Luke K. Rose
April 2018
*/

class Moon :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Moon() {};
	~Moon() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& deltaTime);

private:
	/*
	Private variables
	*/
	float orbitRotation = 180.f;
	GLfloat light_position[4] = { 0, 10, 0, 0 };
	GLfloat light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_ambient[4] = { .1f, .1f, .1f, .1f };
};

