#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/*
Party Animals: Laser (Header File)
Author: Luke K. Rose
April 2018
*/

class Laser :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Laser() ;
	~Laser();
	
	/*
	Public methods
	*/
	void Display();
	void Update(const double& time);

private:
	/*
	Private methods
	*/
	void drawUnit();
	void drawLasers();
	
	/*
	Private variables
	*/
	float red, green, blue, *degree;
};