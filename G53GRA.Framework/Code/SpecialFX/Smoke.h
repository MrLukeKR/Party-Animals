#pragma once
#include "DisplayableObject.h"
#include "Animation.h"



class Smoke :
	public DisplayableObject,
	public Animation 
{
public:
	Smoke(float x, float y, float z, int index, int instances) : index(index), instances(instances){
		emissionLoc[0] = (x);
		emissionLoc[1] = (y);
		emissionLoc[2] = (z);
		memcpy(pos,emissionLoc, sizeof(pos));
	}

	void Display();
	void Update(const double& dT);
private:
	static int fireIndex;
	const int instances;
	int index;
	float deceleration = 0.9f;
	float initSpeed = 1.f;
	float speed = initSpeed;
	float opacity = 1;
	float intensity = (rand() % 3) / 10.0f;
	float emissionLoc[3];
};