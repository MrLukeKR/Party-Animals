#pragma once
#include ".\DisplayableObject.h"
#include ".\Animation.h"

class Sun :
	public DisplayableObject,
	public Animation
{
public:
	Sun();
	~Sun();

	void Display();
	void Update(const double& deltaTime);
private:
	float orbitRotation = 0.f;
	GLfloat light_ambient[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[4] = { 0.0, 1.0, 1.0, 0.0 };
};

