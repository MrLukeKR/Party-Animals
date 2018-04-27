#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Laser :
	public DisplayableObject,
	public Animation
{
public:
	Laser() ;
	~Laser();
	
	void Display();
	void Update(const double& time);

private:
	void drawUnit();
	void drawLasers();
	float red, green, blue;
	float *degree, *x, *y;
};