#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/* 
Party Animals: Giraffe (Header File)
Author: Luke K. Rose
April 2018
*/

class Giraffe :
	public DisplayableObject, 
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Giraffe() {};
	~Giraffe() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private methods
	*/
	void drawGiraffe();
	void drawBody();
	void drawLeg();
	void drawNeck();
	void drawHead();
	void drawTail();
	void drawEyes();
	void drawTongue();
	void drawEars();

	/*
	Private varialbles
	*/
	GLuint giraffeTex = Scene::GetTexture("./Textures/giraffe.bmp");

	float neckAngle = -15, headAngle = -90, offset = 0, neckHeight = 2.f, headHeight = 0.25f;

	bool reverseOffset = false;
};

