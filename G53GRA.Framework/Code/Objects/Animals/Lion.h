#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

#define MOONWALK_RANGE 20

/* 
Party Animals: Lion (Header File)
Author: Luke K. Rose
April 2018
*/
class Lion:
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Lion() {};
	~Lion() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private methods
	*/
	void drawHead();
	void drawBody();
	void drawLeg();
	void drawTail();
	void drawEar();
	void drawEye();
	void drawMouth();

	/*
	Private variables
	*/
	float legAngle = 0, wiggle = 0;
	bool reverseLeg = false, reverseMoonWalk = false, enableSpin = false, reverseWiggle = false;
	float moonwalkX = MOONWALK_RANGE, moonwalkRotation = 0;

	GLuint lionTex = Scene::GetTexture("./Textures/lion.bmp");
};