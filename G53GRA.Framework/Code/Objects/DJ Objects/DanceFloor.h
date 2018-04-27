#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/*
Party Animals: Dance Floor (Header File)
Author: Luke K. Rose
April 2018
*/

class DanceFloor :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	DanceFloor() {};
	~DanceFloor() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private variables
	*/
	int animTime = 0;
	float red[6]   = {0,0,0,1,1,1},
		  green[6] = {0,1,1,0,0,1},
		  blue[6]  = {1,0,1,0,1,0};

};