#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/* 
Party Animals: Monkey (Header File)
Author: Luke K. Rose
April 2018
*/
class Monkey :
	public DisplayableObject,
	public Animation 
{
public:
	/*
	Public Constructor/Destructor
	*/
	Monkey() {};
	~Monkey() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private methods
	*/
	void drawBody();
	void drawLeftArm();
	void drawRightArm();
	void drawHead();
	void drawEye();
	void drawEar();
	void drawSunglasses();
	void drawMouth();
	void drawTail();
	void drawStool();

	/*
	Private variables
	*/
	bool reverseShift = false, reverseOffset = false;
	float elbowRotation = -15, shoulderRotation = -80, headShift = 0, offset = 0;
};