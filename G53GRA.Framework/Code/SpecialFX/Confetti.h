#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Confetti : 
	public DisplayableObject, 
	public Animation {
public:
	Confetti(float x, float y, float z) {
		dropLoc[0] = (x);
		dropLoc[1] = (y);
		dropLoc[2] = (z);
		for (int i = 0; i < 3; i++)
			pos[i] = dropLoc[i] + ((rand() % 100) - 50);
	}

	~Confetti() {};

	void Display();
	void Update(const double& dT);
private:
	float 
	r = (rand() % 10) / 10.0f,
	g = (rand() % 10) / 10.0f,
	b = (rand() % 10) / 10.0f;
	float dropLoc[3];
};