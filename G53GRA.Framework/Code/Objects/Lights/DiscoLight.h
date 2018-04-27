#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/*
Party Animals: Disco Light (Header File)
Author: Luke K. Rose
April 2018
*/

class DiscoLight :
	public DisplayableObject, public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	DiscoLight(GLfloat dirX, GLfloat dirY, GLfloat dirZ, GLenum light, float colorSeed);
	~DiscoLight() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& deltaTime);

private:
	/*
	Private variables
	*/
	float value;
	GLfloat light_position[4] = { pos[0],pos[1],pos[2], 1 };
	GLfloat light_diffuse[4] = { 1, 1, 1, 1.0 };
	GLfloat light_direction[3] = { -1, -1, -1 };
	GLfloat light_specular[4] = { 0,0,0,1 };
	GLfloat light_ambient[4] = { 1, 0.5, 0, 1 };
	GLfloat spot_exponent[1] = { 10 };
	GLfloat spot_cutoff[1] = { 90 };
	GLenum lightSource;
};