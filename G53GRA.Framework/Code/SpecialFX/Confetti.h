#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/*
Party Animals: Confetti (Header File)
Author: Luke K. Rose
April 2018
*/

class Confetti : 
	public DisplayableObject, 
	public Animation {
public:
	/*
	Public Constructor/Destructor
	*/
	Confetti(float x, float y, float z) {
		dropLoc[0] = (x);
		dropLoc[1] = (y);
		dropLoc[2] = (z);
		for (int i = 0; i < 3; i++)
			pos[i] = dropLoc[i] + ((rand() % 100) - 50);
	}

	~Confetti() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private variables
	*/
	float 
	r = (rand() % 10) / 10.0f,
	g = (rand() % 10) / 10.0f,
	b = (rand() % 10) / 10.0f;
	float dropLoc[3];
};