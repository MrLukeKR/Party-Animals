#pragma once
#define _USE_MATH_DEFINES
#include ".\DisplayableObject.h"
#include ".\Animation.h"
#include <cmath>

class Moon :
	public DisplayableObject,
	public Animation
{
public:
	Moon();
	~Moon();

	void Display();
	void Update(const double& deltaTime);
private:
	float orbitRotation = 180.f;
	GLfloat light_position[4] = { 0,1,0,1 };
	GLfloat light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_ambient[4] = { .1f, .1f, .1f, .1f };
};

