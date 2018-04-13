#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Elephant :
	public DisplayableObject, public Animation
{
public:
	Elephant();
	~Elephant();

	void Display();
	void Update(const double& dT);

private:
	void box(float x, float y, float z);
	void drawBody();
	void drawLeg();
	void drawTrunk();
	void drawEyes();
	void drawEars();
	void drawHead();
	void drawTusks();
};