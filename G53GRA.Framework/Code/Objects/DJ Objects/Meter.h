#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/*
Party Animals: Meter (Header File)
Author: Luke K. Rose
April 2018
*/

class Meter :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Meter() {};
	~Meter() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private variables
	*/
	GLuint meterTex = Scene::GetTexture("./Textures/meter.bmp");
	float offset[2] = { 0,0 };
	double time = 0;
};