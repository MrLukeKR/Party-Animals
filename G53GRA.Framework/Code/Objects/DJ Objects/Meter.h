#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Meter :
	public DisplayableObject,
	public Animation
{
public:
	Meter() {};
	~Meter() {};

	void Display();
	void Update(const double& dT);
private:
	GLuint meterTex = Scene::GetTexture("./Textures/meter.bmp");

	float offset[2] = { 0,0 };
	double time = 0;
};