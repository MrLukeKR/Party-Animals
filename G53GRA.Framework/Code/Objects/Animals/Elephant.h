#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/* 
Party Animals: Disco Ball Parrot (Header File)
Author: Luke K. Rose
April 2018
*/

class Elephant :
	public DisplayableObject, 
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Elephant() {};
	~Elephant() {};

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
	void drawLeg();
	void drawTrunk();
	void drawEyes();
	void drawEars();
	void drawHead();
	void drawTusks();

	/*
	Private variables
	*/
	GLuint elephantTex = Scene::GetTexture("./Textures/elephant.bmp");;
	float animationAngle = 0;
	bool reverseAnimation = false;
};