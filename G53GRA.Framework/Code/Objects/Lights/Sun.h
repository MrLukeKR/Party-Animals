#pragma once

#define _USE_MATH_DEFINES

#include ".\DisplayableObject.h"
#include ".\Animation.h"
#include <cmath>

/*
Party Animals: Sun (Header File)
Author: Luke K. Rose
April 2018
*/

class Sun :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Sun() {};
	~Sun() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& deltaTime);

private:
	/*
	Private variables
	*/
	float orbitRotation = 0.f;
	float color[3] = { 1.f,0.647f,0.0f };
	GLfloat light_ambient[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[4] = { 0.0, 1.0, 0.0, 0.0 };
};